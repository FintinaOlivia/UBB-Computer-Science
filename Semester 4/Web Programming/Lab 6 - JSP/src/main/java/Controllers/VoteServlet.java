package Controllers;

import Model.Picture;
import Repository.Database;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

@WebServlet(name = "VoteServlet", value = "/vote")
public class VoteServlet extends HttpServlet {
    Database database;

    public VoteServlet() {
        super();
        database = Database.getInstance();
        System.out.println("VoteServlet initialized");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        int vote = Integer.parseInt(request.getParameter("pickVote"));
        Long photoID = Long.parseLong(request.getParameter("photoID"));

        database.updatePicture(photoID, vote);

        response.sendRedirect("vote.jsp");
    }
}
