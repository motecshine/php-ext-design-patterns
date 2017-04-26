--TEST--
Check for php_design_patterns presence
--SKIPIF--
<?php if (!extension_loaded("php_design_patterns")) print "skip"; ?>
--FILE--
<?php
    use PHPDesign\HelloWorldService;
    use PHPDesign\PlainTextFormatter;
    use PHPDesign\HtmlFormatter;
    /* Bridge Patterns*/
    $service = new HelloWorldService(new HtmlFormatter);
    $service->get();
    $service = new HelloWorldService(new PlainTextFormatter);
    $service->get();
?>
--EXPECT--
<p>Hello World</p>
Hello World
