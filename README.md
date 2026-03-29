# esp32-serial-display

ESP32 com protocolo serial e exibição dos dados recebidos em display LCD I2C 16×2.

## Descrição

Extensão do protocolo serial PSEE com feedback visual: os dados recebidos pelo ESP32 são exibidos em um display LCD 16×2. O display também mostra o estado atual da comunicação ("Begin" / "End").

## Hardware

- Placa: ESP32
- Display: LCD 16×2 com I2C (endereço 0x27)

## Comportamento do display

| Evento | Display linha 1 |
|--------|----------------|
| Recebe `'Y'` | `Begin` |
| Recebe `'W'` | `End` |

## Protocolo serial

Idêntico ao `esp32-serial`:

| Byte | Função |
|------|--------|
| `'Y'` | Início de frame |
| `'W'` | Fim de frame + exibe dados |

## Configuração

- Baud rate: **9600**
- I2C address LCD: `0x27`
- Colunas × Linhas: 16 × 2

## Dependências (Arduino IDE)

- `LiquidCrystal_I2C`

## Escola

Centro Tecnológico Liberato — Novo Hamburgo/RS
