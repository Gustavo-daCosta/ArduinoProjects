import serial
from time import sleep

porta = "COM1"
velocidade = 9600

conexao = serial.Serial (porta, velocidade);

for c in range(0, 50):
    opcao = "a"
    if opcao == "a":
        conexao.write(b'a')
    sleep(0.1)

conexao.close()
