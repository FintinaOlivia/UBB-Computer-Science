<?php
require_once(dirname(__DIR__) . '/Utils/configuration.php');

$userID = $_POST['id'];
$name = $_POST['name'];
$username = $_POST['username'];
$password = $_POST['password'];
$age = $_POST['age'];
$role = $_POST['role'];
$email = $_POST['email'];
$webpage = $_POST['webpage'];

global $connection;

$sql_query = "UPDATE user SET name = ?, username = ?, password = ?, age = ?, role = ?, email = ?, webpage = ? WHERE userID = ?";
$stmt = $connection->prepare($sql_query);

$stmt->bind_param("sssisssi", $name, $username, $password, $age, $role, $email, $webpage, $userID);

if ($stmt->execute()) {
    echo "Your user was updated successfully!";
    header("Location: ../ShowUsers.html");
} else {
    echo "Oops! Something went wrong and your document cannot be updated! Please try again later.";
}

$stmt->close();
mysqli_close($connection);
?>
