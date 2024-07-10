using Microsoft.EntityFrameworkCore;
using System.ComponentModel.DataAnnotations;

namespace FinalBoss.Models
{
    [PrimaryKey(nameof(userID))]
    public class Users
    {
        public int userID { get; set; }
        public string name { get; set; }
        public string username { get; set; }
        public string password { get; set; }
        public int age { get; set; }
        public string role { get; set; }
        public string profile { get; set; }
        public string email { get; set; }
        public string webpage { get; set; }

    }
}
