--TEST--
Check for php_design_patterns presence
--SKIPIF--
<?php if (!extension_loaded("php_design_patterns")) print "skip"; ?>
--FILE--
<?php 
echo "php_design_patterns extension is available";
?>
--EXPECT--
php_design_patterns extension is available
