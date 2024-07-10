package Controllers;

import Model.User;
import Repository.Database;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.*;

import java.io.IOException;

@WebServlet(name = "LoginServlet", value = "/login")
public class LoginServlet extends HttpServlet{
    Database db;
    public LoginServlet() {
        super();
        db = Database.getInstance();
        System.out.println("LoginServlet initialized");
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
//        req.getRequestDispatcher("/index.jsp").forward(req, resp);
        HttpSession session = req.getSession(false);
        if (session != null) {
            session.invalidate();
        }
        resp.sendRedirect(req.getContextPath() + "/index.jsp"); // Redirect to login page
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        System.out.println("DoPost");
        String username = req.getParameter("username");
        String password = req.getParameter("password");

        if(username == null || password == null) {
            System.out.println("Username or password invalid");
            req.setAttribute("error", "Username or password invalid");
            req.getRequestDispatcher("/index.jsp").forward(req, resp);
            return ;
        }
        User user = db.getUserByCredentials(username, password);
        if(user == null) {
            HttpSession session = req.getSession();
            session.setAttribute("fail",true);
            resp.sendRedirect("index.jsp");
        } else {
            HttpSession session = req.getSession();
            session.setAttribute("user", user);
            session.setAttribute("fail",false);
            resp.sendRedirect("home.jsp");
        }
    }
}
