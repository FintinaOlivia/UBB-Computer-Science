<?php
header("Access-Control-Allow-Headers: *");
header("Access-Control-Allow-Origin: *");
require_once "utils/configuration.php";

global $connection;

function insert_user($connection, $name, $username, $password, $age, $role, $email, $webpage) {
    $sql_query = "INSERT INTO user (name, username, password, age, role, email, webpage) VALUES (?, ?, ?, ?, ?, ?, ?)";
    $stmt = $connection->prepare($sql_query);
    $stmt->bind_param("sssisss", $name, $username, $password, $age, $role, $email, $webpage);
    $result = $stmt->execute();
    $stmt->close();
    return $result;
}

if (isset($_POST['name']) && !empty(trim($_POST['name']))) {
    $name = $_POST['name'];
    $username = $_POST['username'];
    $password = $_POST['password'];
    $age = $_POST['age'];
    $role = $_POST['role'];
    $email = $_POST['email'];
    $webpage = $_POST['webpage'];
    $result = insert_user($connection, $name, $username, $password, $age, $role, $email, $webpage);
} else {
    $postdata = file_get_contents("php://input");
    $request = json_decode($postdata);
    if ($request) {
        $name = $request->name;
        $username = $request->username;
        $password = $request->password;
        $age = $request->age;
        $role = $request->role;
        $email = $request->email;
        $webpage = $request->webpage;
        $result = insert_user($connection, $name, $username, $password, $age, $role, $email, $webpage);
    } else {
        $result = false;
    }
}

mysqli_close($connection);

if ($result) {
    echo "Your user was added successfully!";
    header("Location: ../ShowUsers.html");
} else {
    echo "Oops! Something went wrong and your document cannot be added! Please try again later.";
}
