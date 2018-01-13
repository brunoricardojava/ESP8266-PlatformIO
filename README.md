# ESP8266-PlatformIO
Meu repositório de códigos para o micro controlador ESP8266, utilizando o framework PlatformIO.

My repository of codes for MCU ESP8266, using the framework PlatformIO.

## Instalação

## Criando um projeto

>> $ platformio init --board nodemcuv2

## Compilando o projeto

>> $ platformio run

## Upload do código

>> $ platformio run --target upload

## Instalando uma biblioteca

>> $ platformio lib install "numero da biblioteca"

## Pesquisando uma biblioteca

>> $ platformio lib search "nome da biblioteca"

## Usando a serial 

>> $ platformio device monitor [options]

## Usando o sistema de arquivos SPIFFS

OBS: Criar um a pasta de nome "data" no mesmo nivel da pasta "src"

>> $ platformio run -t uploadfs

http://docs.platformio.org/en/latest/userguide/cmd_device.html#cmdoption-platformio-serialports-monitor-f
