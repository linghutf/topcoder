/*
 * @author Lip
 * @date 2015-04-23
 */
public class Heap
	{

		public static void main(String[] args)
			{
				// TODO Auto-generated method stub
				//System.out.println((int)-1.5);
				int []array={4,2,7,9,3,6,1,12,10,5};
				System.out.println("原始：");
				printHeapByLevel(array);
				System.out.println("最小堆：");
				getMinHeap(array);
				printHeapByLevel(array);
				//System.out.println(Math.log(i+1)/Math.log(2));
				
			   sort(array);
               printHeapByLevel(array);
			}
		/*
		 * 堆的性质（最小堆为例）：
		 *    0.根节点为最小值
		 *    1.堆可以看做是一个完全二叉树（即孩子节点从左向右排列）
		 *    2.堆的高度lgn/lg2(n为节点的数目)
		 *    3.第i节点的左孩子节点是2*i+1,右孩子节点为2*i+2
		 *    4.以任意一个节点作为根节点，那么该节点都是堆
		 *    5.可以用一个数据来表示堆
		 */
		/*
		 * 构建堆的原理：
		 *   上滤
		 *   在最后一个节点后建立一个空节点，新插入的节点和父节点比较：
		 *      1，比父节点大，那么直接插入在这个空堆处
		 *      2，比父节点小，那么该父节点下移至该空节点
		 *      3，重复1,2直至插入堆中
		 */
		public static void getMinHeap(int []array)
		{
			for(int i=1;i<array.length;i++)
				insert(array, i);
		}
		//从插入第k个位置的值到堆中，插入一个的最坏情况就是lgN
		public static void insert(int []arrary,int k)
		{
			int insert=arrary[k];
			while(k>0)//一直和父节点比较
				{
					if(insert<arrary[(k-1)/2])//需要插入的元素小于该父节点，那么父节点下移
						{
						   arrary[k]=arrary[(k-1)/2];
						   k=(k-1)/2;
						   if(k==0)
							   arrary[k]=insert;
						}
					else //需要插入的元素大于该父节点，该节点正好可以插在最后一个位置
						{
							arrary[k]=insert;
						    break;
						}
				}
		}
		//按层次打印一个堆
		public static void printHeapByLevel(int []array)
		{
			int height=0;
			for(int i=0;i<array.length;i++)
				{
					int tempHeight=(int)(Math.log(i+1)/Math.log(2));
					if(tempHeight>height)
						{
						   System.out.println();
						   System.out.print(array[i]+" ");
						   height=tempHeight;
						}
					else 
						System.out.print(array[i]+" ");
				}
			System.out.println();
		}
		/*
		 * 二叉树的排序
		 */
		public static void sort(int []array)
		{
			for(int i=0;i<array.length;i++)
				{
					deleteMin(array, array.length-1-i);
				}
		}
		/*
		 * 删除一个根节点，也就是最小值
		 * 那么子节点要上浮
		 * 可以根据此用堆排序
		 * 将删除的最小值放在数组的最后一个位置，节省空间
		 * 根节点为i（0,1,2,3...）
		 * 左孩子节点为：2*i+1
		 * 右孩子节点为：2*i+2
		 * n是剩下的节点
		 */
		public static void deleteMin(int []array,int n)
		{
			int min=array[0];
			int temp=0;//寻找一个孩子填充根节点
			while(2*temp+1<n)//无子节点
				{
					if(array[2*temp+1]>array[2*temp+2])
						{
						  array[temp]=array[2*temp+2];
						  temp=2*temp+2;
						}
					else 
						{
						  array[temp]=array[2*temp+1];
						  temp=2*temp+1;
						}
				}
			//此刻temp为要空，要将最后一个节点值放在temp这个位置上，并且移动temp
			array[temp]=array[n];
			array[n]=min;
			if(temp<n)//要调整的节点后面还有节点
				insert(array, temp);
		}
	}
