using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab_1_WF
{
    public partial class Form1 : Form
    {
        SqlConnection connection;
        SqlDataAdapter dalocations;
        SqlDataAdapter daNPCs;

        DataSet dset;
        BindingSource bslocations;
        BindingSource bsNPCs;

        SqlCommandBuilder cmdBuilder;

        string locationsQuery;
        string NPCsQuery;

        string getConnectionString()
        {
            return "Data Source=DESKTOP-RJ1C8U7\\SQLEXPRESS;Initial Catalog=DnD;Integrated Security=True";
        }

        void FillData()
        {
            // Create a connection to the database
            connection = new SqlConnection(getConnectionString());
            locationsQuery = "SELECT * FROM locations";
            NPCsQuery = "SELECT * FROM NPCs";

            // Create data adapters for the locations and NPCs tables
            dalocations = new SqlDataAdapter(locationsQuery, connection);
            daNPCs = new SqlDataAdapter(NPCsQuery, connection);
            dset = new DataSet();

            // Fill the data set with the tables
            dalocations.Fill(dset, "locations");
            daNPCs.Fill(dset, "NPCs");

            cmdBuilder = new SqlCommandBuilder(dalocations);

            // Create a relation between the locations and NPCs tables
            dset.Relations.Add("LocationInventory",
                dset.Tables["Locations"].Columns["LocationID"], 
                dset.Tables["NPCs"].Columns["LocationID"]);

            //Populating the data grid views
            this.dataGridView1.DataSource = dset.Tables["locations"];
            //this.dataGridView2.DataSource = dset.Tables["NPCs"];
            
            this.dataGridView2.DataSource = this.dataGridView1.DataSource;
            this.dataGridView2.DataMember = "LocationInventory";

            cmdBuilder.GetUpdateCommand();
        }

        public Form1()
        {
            // Initialize the form
            InitializeComponent();
            FillData();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                // Commit any pending edits in the DataGridView
                dataGridView1.EndEdit();
                dataGridView2.EndEdit();

                // Update the data source
                if (dset.HasChanges())
                {
                    // Ensure the connection is open
                    if (connection.State == ConnectionState.Closed)
                        connection.Open();

                    // Generate UpdateCommand for NPCs data adapter
                    SqlCommandBuilder cmdBuilderNPCs = new SqlCommandBuilder(daNPCs);

                    // Update both locations and NPCs tables
                    dalocations.Update(dset, "locations");
                    daNPCs.Update(dset, "NPCs");

                    MessageBox.Show("Database updated successfully.");
                }
                else
                {
                    MessageBox.Show("No changes to update.");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error updating database: " + ex.Message);
            }
            finally
            {
                // Close the connection
                if (connection.State == ConnectionState.Open)
                    connection.Close();
            }
        }

        private void deleteButton_Click(object sender, EventArgs e)
        {
            try
            {
                if (dataGridView2.SelectedRows.Count > 0)
                {
                    int index = dataGridView2.SelectedRows[0].Index;
                    DialogResult dr = MessageBox.Show("Are you sure you want to delete this NPC? This action cannot be undone.", "Confirm Deletion", MessageBoxButtons.YesNo);

                    if (dr == DialogResult.Yes)
                    {
                        // Retrieve the NPC ID from the selected row in the child table
                        int npcID = Convert.ToInt32(dataGridView2.Rows[index].Cells["NPCID"].Value);

                        DataRow[] npcRows = dset.Tables["NPCs"].Select($"NPCID = {npcID}");
                        if (npcRows.Length > 0)
                        {
                            npcRows[0].Delete();
                        }

                        // Configure the DeleteCommand for daNPCs
                        daNPCs.DeleteCommand = new SqlCommand("DELETE FROM NPCs WHERE NPCID = @npcID", connection);
                        daNPCs.DeleteCommand.Parameters.AddWithValue("@npcID", npcID);

                        daNPCs.Update(dset, "NPCs");

                        MessageBox.Show("NPC deleted successfully from database.");

                        dataGridView2.Refresh();
                    }
                }
                else
                {
                    MessageBox.Show("Please select an NPC to delete.");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error deleting NPC: " + ex.Message);
            }
        }
    }
}
