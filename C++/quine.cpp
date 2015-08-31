/**
* @see wikipedia
* @author ywang
* @return Java source code
* @date 2015-8-30
*/

#include <iostream>
#include <string>
// cstring C中的库用于C++, string属于C++标准库
using namespace std;

int main(int argc, char *argv[])
{
    char q = 34;
    string l[] = {
    "       ",
    "=============<<<<<<<< C++ Code >>>>>>>>=============",
    "/**",
    "* @see wikipedia",
    "* @author ywang",
    "* @return Java source code",
    "* @date 2015-8-30",
    "*/",
    "#include <iostream>",
    "#include <string>",
    "using namespace std;",
    "",
    "int main(int argc, char *argv[])",
    "{",
    "   char q = 34;",
    "   string l[] = {",
    "   };",
    "   for (int i = 2; i <= 7; i++)",
    "       cout << l[i] << endl;",
    "   for (int i = 28; i <= 33; i++)",
    "       cout << l[i] << endl;",
    "   for (int i = 0; i <= 42; i++)",
    "       cout << l[0] + q + l[i] + q + ',' << endl;",
    "   for (int i = 34; i <= 42; i++)",
    "       cout << l[i] << endl;",
    "   return 0;",
    "}",
    "=============<<<<<<<< Java Code >>>>>>>>=============",
    "public class Quine",
    "{",
    "   public atatic void main(String[] args)",
    "   {",
    "       char q = 34",
    "       String[] l = {",
    "       }",
    "       for (int i = 2; i <= 15; i++)",
    "           System.out.println(l[i]);",
    "       for (int i = 0; i < l.length; i++)",
    "           System.out.println(l[0] + q + l[i] + q + ',');",
    "       for (int i = 16; i <= 26; i++)",
    "           System.out.println(l[i]);",
    "   }",
    "}",
    };
    for (int i = 2; i <= 7; i++)
        cout << l[i] << endl;
    for (int i = 28; i <= 33; i++)
        cout << l[i] << endl;
    for (int i = 0; i <= 42; i++)
        cout << l[0] + q + l[i] + q + ',' << endl;
    for (int i = 34; i <= 42; i++)
        cout << l[i] << endl;
    return 0;
}


/*
public class Quine
{
  public static void main(String[] args)
  {
    char q = 34;
    String[] l = {
    "    ",
    "=============<<<<<<<< C++ Code >>>>>>>>=============",
    "#include <iostream>",
    "#include <string>",
    "using namespace std;",
    "",
    "int main(int argc, char* argv[])",
    "{",
    "    char q = 34;",
    "    string l[] = {",
    "    };",
    "    for(int i = 20; i <= 25; i++)",
    "        cout << l[i] << endl;",
    "    for(int i = 0; i <= 34; i++)",
    "        cout << l[0] + q + l[i] + q + ',' << endl;",
    "    for(int i = 26; i <= 34; i++)",
    "        cout << l[i] << endl;",
    "    return 0;",
    "}",
    "=============<<<<<<<< Java Code >>>>>>>>==========",
    "public class Quine",
    "{",
    "  public static void main( String[] args )",
    "  {",
    "    char q = 34;",
    "    String[] l = {",
    "    };",
    "    for(int i = 2; i <= 9; i++)",
    "        System.out.println(l[i]);",
    "    for(int i = 0; i < l.length; i++)",
    "        System.out.println( l[0] + q + l[i] + q + ',' );",
    "    for(int i = 10; i <= 18; i++))",
    "        System.out.println(l[i]);",
    "  }",
    "}",
    };
    for(int i = 2; i <= 9; i++)
        System.out.println(l[i]);
    for(int i = 0; i < l.length; i++)
        System.out.println( l[0] + q + l[i] + q + ',' );
    for(int i = 10; i <= 18; i++)
        System.out.println(l[i]);

 }
}
*/
