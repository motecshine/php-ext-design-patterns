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
use PHPDesign\Facade\Facade;
use PHPDesign\Facade\Bios;
use PHPDesign\Facade\Linux;
use PHPDesign\DI\DatabaseConfiguration;
use PHPDesign\DI\DatabaseConnection;
use PHPDesign\Commander\HelloCommand;
use PHPDesign\Commander\Invoker;
use PHPDesign\Commander\Receiver;
use PHPDesign\Commander\AddMessageDateCommand;
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
$service = new HelloWorldService(new PlainTextFormatter);
$service->get();

/* Facade Patterns */
$bios = new Bios();
$linux = new Linux();
$facade = new Facade($linux, $bios);
$facade->turnOn();
echo $facade->os->getName() . "\n";
$facade->turnOff();
echo "\n";

$configuration = new DatabaseConfiguration("127.9.0.1", "3306", "root", "1234");
$connection = new DatabaseConnection($configuration);
$connection->getDsn();


$invoker = new Invoker();
$receiver = new Receiver();
$receiver->enableDate();
$invoker->setCommand(new HelloCommand($receiver));
$invoker->run();
$messageDateCommand = new AddMessageDateCommand($receiver);
$messageDateCommand->execute();
$invoker->run();
$messageDateCommand->undo();
$invoker->run();
var_dump($receiver->getOutput());
?>
