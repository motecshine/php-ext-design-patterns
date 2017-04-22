<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('php_design_patterns')) {
	dl('php_design_patterns.' . PHP_SHLIB_SUFFIX);
}
use PHPDesign\MacFactory;
use PHPDesign\WinFactory;
$macObj = new MacFactory();
$macObj->CreateButton();
$winObj = new WinFactory();
$winObj->CreateButton();
?>
