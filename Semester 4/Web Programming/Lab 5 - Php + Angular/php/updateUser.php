<?php
header("Access-Control-Allow-Headers: *");
header("Access-Control-Allow-Origin: *");
require_once "utils/configuration.php";

function updateUser($connection, $userID, $name, $username, $password, $age, $role, $email, $webpage) {
    $sql_query = "UPDATE user SET name = ?, username = ?, password = ?, age = ?, role = ?, email = ?, webpage = ? WHERE userID = ?";
    $stmt = $connection->prepare($sql_query);
    $stmt->bind_param("sssisssi", $name, $username, $password, $age, $role, $email, $webpage, $userID);
    $stmt->execute();
    $stmt->close();
    mysqli_close($connection);
}

global $connection;

if (isset($_POST['name']) && !empty(trim($_POST['name']))) {
    $userID = $_POST['id'];
    $name = $_POST['name'];
    $username = $_POST['username'];
    $password = $_POST['password'];
    $age = $_POST['age'];
    $role = $_POST['role'];
    $email = $_POST['email'];
    $webpage = $_POST['webpage'];
    
    updateUser($connection, $userID, $name, $username, $password, $age, $role, $email, $webpage);
} else {
    $postdata = file_get_contents("php://input");
    $request = json_decode($postdata);
    $userID = $request->id;
    $name = $request->name;
    $username = $request->username;
    $password = $request->password;
    $age = $request->age;
    $role = $request->role;
    $email = $request->email;
    $webpage = $request->webpage;

    updateUser($connection, $userID, $name, $username, $password, $age, $role, $email, $webpage);
}
?>
