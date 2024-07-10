<?php

header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Headers: *");
header("Access-Control-Allow-Methods: GET, POST, OPTIONS");

// Include the configuration file
require_once 'utils/configuration.php';

// Set default values for "role" and "name" if they are not provided in the $_GET array
$role = isset($_GET["role"]) ? $_GET["role"] : "";
$name = isset($_GET["name"]) ? $_GET["name"] : "";

$sql_query = "SELECT * FROM user;";
global $connection;
$result = mysqli_query($connection, $sql_query);

if ($result) {
    $number_of_rows = mysqli_num_rows($result);
    $requested_users = array();

    for ($i = 0; $i < $number_of_rows; $i++) {
        $row = mysqli_fetch_array($result);
        // Check if the role and name match or if they are empty (meaning any role or name)
        if ((empty($role) || str_contains($row["role"], $role)) && 
            (empty($name) || str_contains($row["name"], $name)))
        {
            array_push($requested_users, array(
                "id" => (int)$row['userID'],
                "name" => $row['name'],
                "username" => $row['username'],
                "age" => (int)$row['age'],
                "role" => $row['role'],
                "email" => $row['email'],
                "webpage" => $row['webpage']
            ));
        }
    }
    mysqli_free_result($result);
    echo json_encode($requested_users);
}
mysqli_close($connection);
?>
