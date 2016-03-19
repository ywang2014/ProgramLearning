/**
	类实现布局
	
	将类分开布局的实例
*/

// create a string identical to sourceString except that the blanks are replaced with underscores.
void EditString::ConvertBlanks(
	char *sourceString,
	char *targetString
	) {
		Assert(strlen(sourceString) <= MAX_STRING_LENGTH);
		Assert(sourceString != NULL);
		Assert(targetString != NULL);
		
		int charIndex = 0;
		do{
			if (sourceString[charIndex] == ' '){
				targetString[charIndex] == '-';
			}
			else{
				targetString[charIndex] = sourceString[charIndex];
			}
			
			charIndex++;
		} while (sourceString[charIndex] != '\0');
}

// ---------------------------------------------------------------------------------------------------
// MATHEMATICAL FUNCTIONS
//
// This class contains the program's mathematical functions.
// ----------------------------------------------------------------------------------------------------

// find the arithmetic maximum of arg1 and arg2
int Math::Max(int arg1, int arg2) {
	if (arg1 > arg2){
		return arg1;
	}
	else {
		return arg2;
	}
}

// find the arithmetic minimum of arg1 and arg2 
int Math::Min(int arg1, int arg2) {
	if (arg1 < arg2) {
		return arg1;
	}
	else {
		return arg2;
	}
}