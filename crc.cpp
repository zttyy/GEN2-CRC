uint8_t Crc5(uint8_t *datain, int size) {

	uint8_t polynomial = 0x9;
	uint8_t crc5 = polynomial;

	//if (size > (sizeof(datain) * 8 + 8))
		//return 0xff;

	int arraySize = size / 8;
	int remainder = size % 8;

	for (int i = 0; i < arraySize; i++)
		for (int j = 7; j >= 0; j--)
			crc5 = (((crc5 & 0x10) >> 4) ^ ((datain[i] & (1 << j))) >> j) ? ((crc5 << 1) ^ polynomial) : (crc5 << 1);

	for (int j = 7; j >= (8 - remainder); j--)
		crc5 = (((crc5 & 0x10) >> 4) ^ ((datain[arraySize] & (1 << j))) >> j) ? ((crc5 << 1) ^ polynomial) : (crc5 << 1);

	return crc5 & 0x1f;
}

uint16_t Crc16(uint8_t *datain, int size) {

	uint16_t polynomial = 0x1021;
	uint16_t crc16 = 0xffff;

	//if (size > (sizeof(datain) * 8 + 8))
		//return 0xffff;

	int arraySize = size / 8;
	int remainder = size % 8;

	for (int i = 0; i < arraySize; i++)
		for (int j = 7; j >= 0; j--) {
			std::cout << std::hex << crc16 << std::endl;

			crc16 = (((crc16 & 0x8000) >> 15) ^ ((datain[i] & (1 << j))) >> j) ? ((crc16 << 1) ^ polynomial) : (crc16 << 1);
	}
	for (int j = 7; j >= (8 - remainder); j--)
		crc16 = (((crc16 & 0x8000) >> 15) ^ ((datain[arraySize] & (1 << j))) >> j) ? ((crc16 << 1) ^ polynomial) : (crc16 << 1);

	return crc16 ^ 0xffff;
}

//test code
//uint8_t cmd[5] = { 0x12, 0x34, 0x56, 0x78, 0x90 };
//uint8_t crc5 = Crc5(cmd, 36);
//uint16_t crc16 = Crc16(cmd, 36);

//std::cout << std::hex << +crc5 << std::endl;
//std::cout << std::hex << +crc16 << std::endl;
