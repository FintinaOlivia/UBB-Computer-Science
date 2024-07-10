<?php
require_once(dirname(__DIR__) . '/Utils/configuration.php');

$name = $_POST['name'];
$username = $_POST['username'];
$password = $_POST['password'];
$age = $_POST['age'];
$role = $_POST['role'];
$email = $_POST['email'];
$webpage = $_POST['webpage'];

global $connection;

$sql_query = "INSERT INTO user (name, username, password, age, role, email, webpage) VALUES (?, ?, ?, ?, ?, ?, ?)";
$stmt = $connection->prepare($sql_query);

$stmt->bind_param("sssisss", $name, $username, $password, $age, $role, $email, $webpage);

if ($stmt->execute()) {
    echo "Your user was added successfully!";
    header("Location: ../ShowUsers.html");
} else {
    echo "Oops! Something went wrong and your document cannot be added! Please try again later.";
}

$stmt->close();
$connection->close();
?>
