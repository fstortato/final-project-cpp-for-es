<?php
	include("connection.php");

	$conn = new mysqli($serverName, $userName, $password, $dbName);

	// Check connection

	if ($conn->connect_error) echo ("Error - Connection failed: " . $conn->connect_error);
	else {
		$sql = "SELECT * FROM events";
		$result = $conn->query($sql);
		if ($conn->error) echo "Error - Server error while consulting database: " . $conn->connect_error;
		else {
			$resultsFound = $result->num_rows;
			if ($resultsFound > 0) {				
				$i = 0;
				echo "[";
				while($row = $result->fetch_assoc()) {
				$i = $i + 1;
				$return["id"] = $row["event_id"];
				$return["sourceId"] = $row["source_registry"];
				$return["targetId"] = $row["target_registry"];
				$return["type"] = $row["event_type"];
				$return["diffCredCellphone"] = $row["diff_cred_cellphone"];
				$return["diffCredTag"] = $row["diff_cred_tag"];
				$return["toResolve"] = $row["to_resolve"];
				$return["time"] = $row["event_time"];
				echo json_encode($return);
				if ($i != ($resultsFound)) echo ",";
				}
				echo "]";
			}
			else {
				echo "Error - No user found";
			}
		}
	}

?>