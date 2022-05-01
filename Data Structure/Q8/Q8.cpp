#include<iostream>
#include<algorithm>
#include<iomanip>


#include<iostream>
#include<vector>
#include<ctime>
#include<chrono>
#include<ratio>
using namespace std ;
using namespace std::chrono;
using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    int binarySearch(vector<int> arr, int item , int low , int end) {
    int s = 0 , e = end - 1;
            while(s <= e){
                int mid = (s + e)/2;
                if(arr[mid] > item){
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }
            return s;
}
//Abstract Class Sorter
class Sorter{
    public:
    virtual void  SortM( vector<int>arr ,int n) {}
};

//First Child Of Sorter (insertion)
        class insertionSorter:public Sorter{
            public:
             void SortM(vector<int> arr , int n){
                  for(int i=1,j;i<n;i++){
        int tmp=arr[i];
        for(j=i;j>0&&tmp<arr[j-1];j--){
            arr[j]=arr[j-1];
        }
        arr[j]=tmp;
       
    }
            }
        };


//Second Child Of Sorter binar
    class Binaryinsertionsort:public Sorter{
        public:
        void SortM(vector<int> arr,int n){
             int loc,j,selected;
                for(int i=1;i<n;i++){
                    j=i-1;
                    selected=arr[i];
                    loc=binarySearch(arr,selected,0,j);
                    while(j>=loc){
                        arr[j+1]=arr[j];
                        j--;
                    }
                    arr[j+1]=selected;

                }
        }
    };


class testBed {
    public :

    // GENERATE RANDOM LIST
    vector <int> GenerateRandomList ( int mn , int mx , int size ) {
        vector <int> res(size) ;

        for ( int i = 0 ; i < size ; i++ ) {
            // generate element
            int rand_element = ( rand() %( mx + 1) )   ;

            res[i]=rand_element;
        }
        return res ;
    }

    // GENERATE REVERSED ORDERD RANDOM LIST
    vector <int> GenerateReverseOrderedList( int mn , int mx , int size ){
        vector <int> res = GenerateRandomList(mn,mx,size);
        sort(res.begin(),res.end());
        reverse(res.begin(),res.end());
        return res;
    }

    /*Pre: Takes a sorting type (QuickSort || SelectionSort) , Unsorted Vector and Size
  Post: Return Calculated Time for sort opeartion*/
  double RunOnce(Sorter* SortType ,vector<int> data,int size){
        auto t1 = high_resolution_clock::now();
        SortType->SortM(data, size);
        auto t2 = high_resolution_clock::now();
        auto ms_int = duration_cast< milliseconds >(t2 - t1);

        return ms_int.count();
  }


    // RUN AND AVERAGE
    long double RunAndAverage (  Sorter * custom_sort , bool type , int mn , int mx , int size , int sets_num ) {
         vector <int> sample  ;

        double TotalTime = 0 ;
        for ( int i = 0 ; i < sets_num ; i++ ) {
            // generate sample

            // Descion what type you will generate
            sample = ( type ? GenerateReverseOrderedList ( mn , mx , size ) : GenerateRandomList ( mn , mx , size ) ) ;

            // append to total time consumed
            TotalTime += RunOnce( custom_sort , sample , size ) ;
        }

        double TotalAverageTime = TotalTime / sets_num ;
        return TotalAverageTime ;
    }

    // RUN EXPERIMENT
    void RunExperiment ( Sorter * custom_sort ,bool type , int mn , int mx , int min_val , int max_val , int sets_num , int step ) {


        cout << "EXPERIMNET REPORT ::::::::: " << endl ;

        // Run an Experiment
        double AverageTime ; 
        for ( int i = min_val ; i <= max_val ; i+= step ) {
            AverageTime = RunAndAverage( custom_sort , type , mn , mx , i ,sets_num ) ;


            cout << i << " " << setw(10) << AverageTime << " Miliseconds" << endl ;
        }

    

    }
};



int main(){
    testBed x ;
    Sorter * custom_sort = new insertionSorter ;
    bool type = true ;
    int mn = 1000 , mx = 100000 , min_val = 1000 , max_val= 10000 , sets_num = 200 , step = 500 ;
    x.RunExperiment(custom_sort, 1, 10000, 100000, 1000, 10000, 200, 500 );


    return 0;
}



