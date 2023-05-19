def Crc5(datain, size):
    polynomial = 0x9
    crc5 = polynomial
    if size > len(datain):
        return 0xff
    for i in range(size):
        if ((crc5 >> 4) & 0x1) ^ datain[i]:
            crc5 = ((crc5 << 1) ^ polynomial) & 0x1f
        else:
            crc5 = (crc5 << 1) & 0x1f
    return crc5
  
def Crc16(datain, size):
  polynomial = 0x1021
  crc16 = 0xffff
  if size > len(datain):
      return 0xffff
  for i in range(size):
      if ((crc16 >> 15) & 0x1) ^ datain[i]:
          crc16 = ((crc16 << 1) ^ polynomial) & 0xffff
      else:
          crc16 = (crc16 << 1) & 0xffff
  return crc16 ^ 0xffff

#test code
#list = [1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1]
#print(Crc5(list, len(list)))
#print(Crc16(list, len(list)))
