<?php
	// Set default timezone
	date_default_timezone_set('Brazil/East');

	// Open and close times + buffer
	$lunchBeginning = date('H:i', mktime(10,40));
	$lunchEnd = date('H:i', mktime(14, 10));
	$dinnerBeggining = date('H:i', mktime(16,40));
	$dinnerEnd = date('H:i', mktime(19,40));

	// Return to the board if the university restaurant is oppened or not
	if ((date('H:i') > $lunchBeginning && date('H:i') < $lunchEnd) || (date('H:i') > $dinnerBeggining && date('H:i') < $dinnerEnd)) echo true;
	else echo false;

?>