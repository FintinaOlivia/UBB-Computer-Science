<%@ page import="Repository.Database" %>
<%@ page import="Model.Picture" %>
<%@ page import="Model.User" %><%--
  Created by IntelliJ IDEA.
  User: Theo
  Date: 26-May-24
  Time: 21:25
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Vote</title>
    <style>
        body {
            margin: 0;
            padding: 0;
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            min-height: 100vh;
            background-color: #1a1a1a; /* Dark background color */
            font-family: "Arial", sans-serif;
            color: white; /* Text color */
        }

        h3 {
            margin-bottom: 20px;
        }

        .container {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
            gap: 20px;
            width: 80%;
        }

        .button {
            border-radius: 8px;
            background-color: #37a7e8;
            padding: 10px 20px;
            margin: 10px;
            cursor: pointer;
            transition: background-color 0.3s;
            color: white;
            border: none;
            text-decoration: none;
            display: inline-block;
        }

        .button:hover {
            background-color: #92d0ff;
        }

        #photoID {
            display: none;
        }

        .photoData {
            background-color: #444444;
            border-radius: 8px;
            padding: 20px;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.3);
            text-align: center;
        }

        .photoData img {
            border-radius: 8px;
            max-width: 100%;
        }

        .photoData p, .photoData label {
            color: white;
        }

        .button-container {
            display: flex;
            justify-content: center;
            width: 100%;
        }
    </style>
</head>
<body>
<h3>See all photos and vote</h3>
<br>

<div class="container">
    <%
        User user = (User) session.getAttribute("user");

        if (user == null) {
            response.sendRedirect("index.jsp");
            return;
        }

        Database db = new Database();
        for(Picture picture: db.getAllPictures()){
    %>

    <form method="post" action="<%= request.getContextPath() %>/vote" class="photoData">
        <img width="200" height="200" src="images/<%=picture.getUrl()%>" alt="Picture">

        <p>Author: <%=picture.getUser().getUsername()%></p>

        <input type="hidden" id="photoID" name="photoID" value="<%=picture.getPictureId()%>">
        <p>Number of votes: <%= picture.getVotes() %></p>

        <%
            if (!picture.getUser().getUsername().equals(user.getUsername())) {
        %>
            <label for="pickVote">Choose your vote (between 1 and 10):</label>
            <input type="range" min="1" max="10" value="5" id="pickVote" name="pickVote">
            <input class="button" type="submit" value="Vote">
        <%
        } else {
        %>
            <p>You cannot vote for your own photo.</p>
        <%
            }
        %>
    </form>
    <%
        }
    %>
</div>
<div class="button-container">
    <button class="button" onclick="document.location = 'home.jsp'">Go back</button>
</div>
<br><br>
</body>
</html>
