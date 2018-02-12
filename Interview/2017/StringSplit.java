/**
	闪银二面 笔试题
	将一个字符串按照给出的分隔符分割。不能出现空格、空字符串的分割。
	"a###b" "#" --> "a" "b"
*/

List<String> strToken(String sentence, String delimitor){
    if (sentence == null || delimitor == null){
        return new ArrayList<>();
     }
     List<String> tokens =  new ArrayList<>();
     StringBuilder buffer = new StringBuilder();
     for (int i = 0; i < sentence.length(); i++){
         char currentChar = sentence.charAt(i);
         if (!delimitor.contains(currentChar)){
             buffer.append(currentChar);
          } else {
              if (buffer.size() > 0){
                  tokens.add(buffer.toString());
               }
               buffer.delete();
          }
     }
     return tokens;
 }