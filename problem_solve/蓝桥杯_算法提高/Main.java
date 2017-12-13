import java.util.Calendar;
import java.util.Collection;
import java.util.Scanner;

class Main
{
    public static void main(String[] args)
    {
        int year;
        int month;
        int day;
        Scanner in = new Scanner(System.in);
        year = in.nextInt();
        month =in.nextInt();
        day = in.nextInt();

        Calendar calendar = Calendar.getInstance();
        calendar.set(year,month-1,day);
        // System.out.println(calendar.YEAR + " "+ calendar.MONTH + " " + calendar.DATE);
        int weekday = calendar.get(Calendar.DAY_OF_WEEK);
        if (weekday == 1)  
        System.out.println(7);  
         else   
        System.out.println(weekday - 1); 
    }
}