package Controllers;

import Model.Picture;
import Model.User;
import Repository.Database;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.Cookie;

import java.io.IOException;

@WebServlet(name = "UploadServlet", value = "/upload")
public class UploadServlet extends HttpServlet{
    Database db;

    public UploadServlet() {
        super();
        db = Database.getInstance();
        System.out.println("UploadServlet initialized");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        String username = null;
        Cookie[] cookies = request.getCookies();
        if (cookies != null) {
            for (Cookie cookie : cookies) {
                if (cookie.getName().equals("user")) {
                    username = cookie.getValue();
                    break;
                }
            }
        }

        User user = db.getUserByUsername(username);
        String url = request.getParameter("pictureUpload");

        if(user == null) {
            response.sendRedirect("/login");
            return ;
        }

        if(url != null && !url.isEmpty()) {
            Picture photo = new Picture();
            photo.setUrl(url);
            photo.setUser(user);
            photo.setVotes(0);

            db.addPicture(photo);
        }

        response.sendRedirect("home.jsp");
    }
}

