<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('php_design_patterns')) {
	dl('php_design_patterns.' . PHP_SHLIB_SUFFIX);
}
use PHPDesign\MacFactory;
use PHPDesign\WinFactory;
use PHPDesign\Book;
use PHPDesign\Kindle;
use PHPDesign\EbookAdapter;
use PHPDesign\HelloWorldService;
use PHPDesign\PlainTextFormatter;
use PHPDesign\HtmlFormatter;

$macObj = new MacFactory();
$macObj->CreateButton();
$winObj = new WinFactory();
$winObj->CreateButton();

$bookObj = new Book();
$bookObj->open();
$bookObj->turnPage();
var_dump($bookObj->getPage());

$kindle = new Kindle();
$kindle->unlock();
$kindle->pressNext();
var_dump($kindle->getPage());

$ebookAdapter = new EbookAdapter(new Kindle());

$ebookAdapter->open();
$ebookAdapter->turnPage();
var_dump($ebookAdapter->getPage());

/* Bridge Patterns*/
$service = new HelloWorldService(new HtmlFormatter);

$service->get();
$htmlFormatter = new HtmlFormatter();
echo $htmlFormatter->format("ss");
$PlainTextFormatter = new PlainTextFormatter();
echo $PlainTextFormatter->format("ss");
?>
