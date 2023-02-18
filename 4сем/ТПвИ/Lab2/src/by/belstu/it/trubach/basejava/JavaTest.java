package by.belstu.it.trubach.basejava;

import static java.lang.Math.log;

/** Пример класса
 * @author Дима$$
 * @version 1.0
 * */
public class JavaTest {

    // c)

    // разница между final и static final в том,
    // что final переменная может быть изменена только в конструкторе,
    // а static final переменная может быть изменена только в статическом методе
    public final int a = 1;
    public static final int b = 2;

    /** Метод main
     *
     *
     * @param args - стринговый массив
     * @return void
     * */

    public static void main(String[] args) {

        System.out.println("========== B) ==========");
        char c_var = 'a';
        String str = "Hello";
        int i_var = 100;
        short s_var = 200;
        double d_var = 3.14;
        byte b_var = 127;
        long l_var = 1000000000000000000L;
        boolean bool = true;

        System.out.println("Результат string + int: " + str + i_var);
        System.out.println("Результат string + char: " + str + c_var);
        System.out.println("Результат string + double: " + str + d_var);

        byte b_var2; int i_var2; long l_var2;

        b_var2 = (byte) (b_var + i_var);
        System.out.println("Результат byte = byte + int: " + b_var2);

        i_var2 = (int) (d_var + l_var);
        System.out.println("Результат int = double + long: " + i_var2);

        l_var2 = (long) (i_var + 2147483647);
        System.out.println("Результат long = int + int: " + l_var2);

        boolean bool2 = (bool == true) && (bool == false);
        System.out.println("Результат boolean = boolean && boolean: " + bool2);

        boolean bool3 = (bool == true) ^ (bool == false);
        System.out.println("Результат boolean = boolean ^ boolean: " + bool3);

        //boolean bool4 = (bool == true) + (bool == true); - ошибка

        long l_var3 = 9223372036854775807L;
        long l_var4 = 0x7fff_ffff_fffL; // 8796093022207

        char c1 = 'a'; char c2 = '\u0061'; char c3 = 97;
        System.out.println("Числа: " + c1 + " " + c2 + " " + c3 + "\nИх сумма: " + (c1 + c2 + c3));

        System.out.println("3.45 % 2.4 =  " + 3.45 % 2.4);
        System.out.println("1.0/0.0 =  " + 1.0/0.0);
        System.out.println("0.0/0.0 =  " + 0.0/0.0);
        System.out.println("log(-345) =  " + log(-345));

        System.out.println("Float: " + Float.intBitsToFloat(0x7F800000));
        System.out.println("Float: " + Float.intBitsToFloat(0xFF800000));

        System.out.println("========== D) ==========");
        System.out.println("Вывод Math.PI: " + Math.PI);
        System.out.println("Вывод Math.E: " + Math.E);
        System.out.println("Округление Math.PI: " + Math.round(Math.PI) );
        System.out.println("Округление Math.E: " + Math.round(Math.E) );
        System.out.println("Минимальное из: " + Math.min(Math.PI, Math.E) );
        System.out.println("Генерация случайного числа: " + Math.random() );

        System.out.println("========== E) ==========");
        // Создать объекты разных классов оболочек и вывести их на экран
        Boolean bool_shell = new Boolean(true);
        Character char_shell = new Character('b');
        Integer int_shell = new Integer(200);
        Byte byte_shell = new Byte((byte) 127);
        Short short_shell = new Short((short) 200);
        Long long_shell = new Long(10000000000000000L);
        Double double_shell = new Double(3.14);

        System.out.println("Integer: " + int_shell);
        System.out.println("200 >>> 1: " + (int_shell >>> 1));
        System.out.println("-200 >>> 1: " + (-int_shell >>> 1));
        System.out.println("200 >> 2: " + (int_shell >> 2));
        System.out.println("true ~ false: " + (true ^ false)); // ^ - исключающее ИЛИ
        System.out.println("true & false: " + (true & false)); // & - И

        System.out.println(String.format(
                "long_min: %s, long_max: %s, double_min: %s, double_max: %s",
                Long.MIN_VALUE,Long.MAX_VALUE,Double.MIN_VALUE,Double.MAX_VALUE));

        // выполнить упаковку и распаковку для типов Integer и Byte
        Integer pack = 200; // упаковка
        int unpack = pack; // распаковка

        int i = Integer.parseInt("10");
        System.out.println(i);
        int val = 255;
        System.out.println("Integer: " + val);
        System.out.println("Hex String = " + Integer.toHexString(val));
        int a = 20;
        int b = 10;
        System.out.println("Compare a and b: " + Integer.compare(a, b));
        System.out.println("Integer.toString(10): " + Integer.toString(10) + " Type: " + Integer.toString(10).getClass().getName());
        System.out.println("Integer.bitCount(10): " + Integer.bitCount(10));
        Double f1 = new Double(0.0/0.0);
        System.out.println("Double.isNaN(0.0/0.0): " + f1.isNaN());

        System.out.println("========== F) ==========");
        String s34 = "2345";
        int s35 = Integer.parseInt(s34);
        Integer i2 = Integer.valueOf(s34);
        System.out.println("String to int: " + s35);
        System.out.println("String to Integer: " + i2);

        byte[] toArr = s34.getBytes();
        System.out.println("Переводит строки в массив байтов = " + toArr);

        String backToStr = new String(toArr);
        System.out.println("Переводит массив байтов в строку = " + backToStr);

        // Преобразование строки в bool двумя способами
        String s36 = "true";
        boolean b1 = Boolean.parseBoolean(s36);
        boolean b2 = Boolean.valueOf(s36);
        System.out.println("String to boolean: " + b1 + " " + b2);

        String strComp = "Tolya";
        String strComp2 = "Tolya";
        System.out.println(strComp == strComp2);
        System.out.println(strComp.equals(strComp2));
        System.out.println(strComp.compareTo(strComp2));
        System.out.println();

        strComp2 = null;
        System.out.println("Если одна строка null");
        System.out.println(strComp == strComp2);
        System.out.println(strComp.equals(strComp2));
        // System.out.println(strComp.compareTo(strComp2));

        String strExample = "Hello world";
        System.out.println(strExample.split(" ")[0]);
        System.out.println(strExample.contains("He"));
        System.out.println(strExample.hashCode());
        System.out.println(strExample.indexOf("l"));
        System.out.println(strExample.length());
        System.out.println(strExample.replace("l", "L"));

        System.out.println("========== G) ==========");
        char[][] c11 = new char[3][];
        char[] c22[] = new char[2][3];
        char c33[][] = new char[2][3];
        c11[0] = new char[1];
        c11[1] = new char[2];
        c11[2] = new char[3];

        System.out.println(c11.length);
        System.out.println(c11[0].length);
        System.out.println(c11[1].length);
        System.out.println(c11[2].length);

        c22[0][0] = 'a';
        c22[0][1] = 'b';
        c22[0][2] = 'c';
        c22[1][0] = 'd';
        c22[1][1] = 'e';
        c22[1][2] = 'f';

        c33[0][0] = 'a';
        c33[0][1] = 'b';
        c33[0][2] = 'c';
        c33[1][0] = 'd';
        c33[1][1] = 'e';
        c33[1][2] = 'f';

        boolean comRez = c22==c33;
        System.out.println(comRez);
        System.out.println(c22=c33);

        for (char aa[]: c33) {
            for (char b__: aa) {
                System.out.println(b__);
            }
        }

        System.out.println("========== H) ==========");
        WrapperString WSElem = new WrapperString("Strochka");

        WSElem.replace('a', 'b');
        System.out.println(WSElem.getPstr());

        WrapeprString AWS = new WrapeprString() {
            public String pstr = "";
            @Override
            public void replace(char oldchar, char newchar) {
                pstr = pstr.replace(oldchar, newchar);
            }
            public void delete(char newchar){
                pstr = pstr.replace(newchar, ' ');
                pstr = pstr.trim();
            }
        };


    }
}
