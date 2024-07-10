package Controllers;

import Repository.Database;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

@WebServlet(name = "TopPicturesController", value = "/top-pictures")
public class TopPicturesServlet extends HttpServlet {
    Database database;

    public TopPicturesServlet() {
        super();
        database = Database.getInstance();
        System.out.println("TopPicturesController initialized");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        if(request.getParameter("topNPictures") == null)
            request.getSession().setAttribute( "topNPictures", null);
        else {
            int topNr = Integer.parseInt(request.getParameter("topNPictures"));
            request.getSession().setAttribute("topNPictures", topNr);
            response.sendRedirect("top-pictures.jsp");
        }
    }
}
