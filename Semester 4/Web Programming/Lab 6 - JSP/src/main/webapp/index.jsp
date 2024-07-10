<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" language="java" %>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
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
            color: #ffffff;
        }

        .container {
            background-color: #333333;
            border-radius: 8px;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.3);
            padding: 40px;
            text-align: center;
        }

        h3 {
            margin-bottom: 20px;
        }

        input[type="text"],
        input[type="password"] {
            width: 100%;
            padding: 10px;
            margin-bottom: 20px;
            border: 1px solid #555555;
            border-radius: 4px;
            box-sizing: border-box;
            background-color: #444444;
            color: #ffffff;
        }

        button {
            width: 100%;
            padding: 10px;
            background-color: #4CAF50;
            color: white;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            transition: background-color 0.3s;
        }

        button:hover {
            background-color: #45a049;
        }

        .error {
            color: #ff3333;
        }
    </style>
</head>
<body>
<div class="container">
    <h3>Login</h3>

    <% if(session.getAttribute("success") != null && session.getAttribute("success").equals(true)) { %>
        <h3>Login Successful!</h3>
    <% } else { %>
        <% if(session.getAttribute("fail") != null && session.getAttribute("fail").equals(true)) { %>
            <p class="error">Login failed, please try again.</p>
        <% } %>
    <% } %>

    <form action="<%= request.getContextPath() %>/login" method="post">
        <label for="username">Username</label><br>
        <input type="text" id="username" name="username"><br>
        <label for="password">Password</label><br>
        <input type="password" id="password" name="password"><br><br>
        <button type="submit">Login</button>
    </form>
<%--    <form action="<%= request.getContextPath() %>/home.jsp" method="post">--%>
<%--        <button type="submit">Login</button>&ndash;%&gt;--%>
<%--    </form>--%>
</div>
</body>
</html>
