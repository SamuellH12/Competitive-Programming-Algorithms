import java.util.*;

class calcada {
    public static void main(String[] args) {
       	Scanner entrada = new Scanner(System.in);
        
        int n = entrada.nextInt();
        int [] c = new int[n];
        for(int i=0; i < n; i++)
        {
            c[i] = entrada.nextInt();
        }

        long resp = 1;
        int a, b;

        for(int i=0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                a = c[i];
                b = c[j];

                if( b == a)
                {
                    continue;
                }
                int seq = 2;

                int x = j+1;
                while( x < n )
                {
                    if(a == c[x])
                    {
                        seq++;
                        int temp = a;
                        a = b;
                        b = temp;
                    }
                    x++;
                }

                if( seq > resp)
                {
                    resp = seq;
                }

            }

        }

        System.out.println(resp);
        
    }
}