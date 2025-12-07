package collections;

import java.util.concurrent.CopyOnWriteArrayList;
/* This collection creates snapshots while reading and writing
 * and while writing insertion updation is atomic and new updated
 * version is replaced with the older one once updation insertion completes
 */
class Example19 {     
    public static void main(String[] args) {
        CopyOnWriteArrayList<Integer> copyOnWriteArrayList=new CopyOnWriteArrayList<>();
        new Thread(()->{
            int i=0;
            while (i<5)
            {   try {
                    Thread.sleep(1000);
                } catch (Exception e) {
                    e.printStackTrace();
                };
                copyOnWriteArrayList.add(i++);
            }
        }).start();
        new Thread(()->{
            int j=5;while (j<10)
            {   try {
                    Thread.sleep(2000);
                } catch (Exception e) {
                    e.printStackTrace();
                };
                copyOnWriteArrayList.add(j++);
            }
        }).start();
        new Thread(()->{
            int i=0;
            while (i<15)
            {   try {
                    Thread.sleep(1500);
                } catch (Exception e) {
                    e.printStackTrace();
                };
                System.out.println(copyOnWriteArrayList);
            }
        }).start();
    }
}