/**
	善用代码重用
	
	编写一个函数，检查某个二进制数是否等于十六进制数(都是字符串表示的)
*/

class NumberEqual{
	public boolean compareBinToHex(String binary, String hex){
		int n1 = convertToBase(binary, 2);
		int n2 = convertToBase(hex, 16);
		
		if (n1 < 0 || n2 < 0){
			return false;
		}
		else{
			return n1 == n2;
		}
	}
	
	public int charToDigit(char ch){
		if (ch >= '0' && ch <= '9'){
			return ch - '0';
		}
		else if (ch >= 'A' && ch <= 'F'){
			return 10 + ch - 'A';
		}
		else if (ch >= 'a' && ch <= 'f'){
			return 10 + ch - 'a';
		}
		
		return -1;
	}
	
	public int convertToBase(String number, int base){
		if (base < 2 || (base > 10 && base != 16)){
			return -1;	// invalid arguments
		}
		
		int value = 0;
		// 字符串没有0x起始位吗？
		for (int i = number.length() - 1; i >= 0; i--){
			int digit = charToDigit(number.charAt(i));
			if (digit < 0 || digit >= base){
				return -1;
			}
			int exp = number.length() - 1 - i;
			value += digit * Math.pow(base, exp);
		}
		
		return value;
	}
}