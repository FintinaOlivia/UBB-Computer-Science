<%@ page import="Model.User" %>
<%@ page import="Repository.Database" %>
<%@ page import="Model.Picture" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home</title>
    <style>
        body {
            margin: 0;
            padding: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            background-color: #1a1a1a;
            font-family: "Arial", sans-serif;
            color: white;
        }

        .container {
            text-align: center;
            background-color: #333333;
            border-radius: 8px;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.3);
            padding: 40px;
        }

        .button {
            border-radius: 8px;
            background-color: #4CAF50;
            padding: 10px 20px;
            margin: 10px;
            cursor: pointer;
            transition: background-color 0.3s;
        }

        .button:hover {
            background-color: #3a8a3e;
        }

        #pictureUpload {
            margin: 10px;
            border-radius: 10px;
        }

        .table {
            margin-top: 20px;
            border-collapse: collapse;
            width: 100%;
        }

        .table td, .table th {
            border: 1px solid #797979;
            text-align: left;
            padding: 8px;
        }

        .table tr:nth-child(even) {
            background-color: #a8a8a8;
        }

        .table tr:hover {
            background-color: #ddd;
        }
    </style>
</head>
<body>
<%
    String topNPicturesParam = request.getParameter("topNPictures");
    if (topNPicturesParam != null) {
        try {
            int topNr = Integer.parseInt(topNPicturesParam);
            request.getSession().setAttribute("topNPictures", topNr);
            response.sendRedirect("top-pictures.jsp");
            return;
        } catch (NumberFormatException e) {
            // Do nothing
        }
    }
%>
<div class="container">
    <%  User user = (User) session.getAttribute("user");
        if(user == null) {
            response.sendRedirect("index.jsp");
            return;
        }
        else {
    %>
    <br><br><h3>Hello, <%=user.getName()%>!</h3>
    <%
        }
    %>

    <button class="button" onclick="document.location = 'vote.jsp'">See all photos</button>

    <form action="<%= request.getContextPath() %>/upload" method="post">
        <label for="pictureUpload">Upload a new photo:</label>
        <input type="file" id="pictureUpload" name="pictureUpload" accept="image/*"><br>
        <input class="button" type="submit" id="upload" value="Upload">
    </form>

    <form action="<%= request.getRequestURI() %>" method="post">
        <label for="topNPictures">Please write the number of pictures you'd like to see:</label>
        <input type="text" id="topNPictures" name="topNPictures" size="3"><br>
        <input class="button" id="seeTopBtn" type="submit" value="See top photos">
    </form>

    <table class="table">
        <%
            if (session.getAttribute("topNPictures") != null) {
                Integer topNPictures = (Integer) session.getAttribute("topNPictures");
                Database db = new Database();
                for (Picture picture : db.getTopNMostVotedPictures(topNPictures)) {
        %>
        <%
                }
            }
        %>
    </table>
    <form action="<%= request.getContextPath() %>/home" method="get">
        <input class="button" type="submit" id="logout_button" value="Log out">
    </form>
<%--    <button class="logout_button">Logout</button>--%>
</div>
</body>
</html>
