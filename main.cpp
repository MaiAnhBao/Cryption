/*
 * main.cpp
 *
 *  Created on: 11 juil. 2016
 *      Author: hnnguyen
 */

#include <iostream>
#include <chrono> // clock functions
////#include <fstream>
////#include <string>
//#include <stdio.h>
//#include <memory>
//
//using namespace std;
//
//class C {
//public:
//	C() {
//		printf("Constructor for C:  this=%p\n", this);
//	}
//	~C() {
//		printf("Destructor for C:  this=%p\n", this);
//	}
//
//private:
//	shared_ptr<C> pC;
//
//public:
//	void setSharedPointer(shared_ptr<C> p) {
//		pC = p;
//	}
//
//
//};
//
//int main(int argc, char **argv) {
//
//	//ios_base::ate vs ios_base::app
////	ofstream a;
////	a.open("1.txt", ios_base::ate);
////	a << "123";
////	a.close();
////	ofstream b;
////	b.open("1.txt", ios_base::app);
////	b << "456";
////	b.close();
////	ifstream c;
////	c.open("1.txt");
////	string str;
////	c >> str;
////	cout << str;
////	return 0;
//
//
//	//Memory leak of smart pointer
//	shared_ptr<C> pC(new C);
//	shared_ptr<C> pD(new C);
//
//	pC->setSharedPointer(pD);
//	pD->setSharedPointer(pC);
//
//	return 0;
//}
//#include <iostream>
//#include <vector>
//
//struct A
//{
//  virtual void bar(void) { std::cout << "one" << std::endl; }
//};
//
//struct B : public A
//{
//  virtual void bar(void) { std::cout << "two" << std::endl; }
//};
//
//void test(std::vector<A*> objs, void (A::*fun)())
//{
//  for (auto o = objs.begin(); o != objs.end(); ++o)
//  {
//    A* obj = (*o);
//    (obj->*fun)();
//  }
//}
//
//int main()
//{
//  std::vector<A*> objs = {new A(), new B()};
//
//  test(objs, &A::bar);
//}

//#include <winsock.h>
//#include <stdlib.h>
//#include <iostream>
//
//using namespace std;
//
//extern int DoWinsock(const char* pcHost, int nPort);
//
//const int kDefaultServerPort = 4242;
//
//int main(int argc, char **argv) {
//	// Do we have enough command line arguments?
//	    if (argc < 2) {
//	        cerr << "usage: " << argv[0] << " <server-address> " <<
//	                "[server-port]" << endl << endl;
//	        cerr << "\tIf you don't pass server-port, it defaults to " <<
//	                kDefaultServerPort << "." << endl;
//	        return 1;
//	    }
//
//	    // Get host and (optionally) port from the command line
//	    const char* pcHost = argv[1];
//	    int nPort = kDefaultServerPort;
//	    if (argc >= 3) {
//	        nPort = atoi(argv[2]);
//	    }
//
//	    // Do a little sanity checking because we're anal.
//	    int nNumArgsIgnored = (argc - 3);
//	    if (nNumArgsIgnored > 0) {
//	        cerr << nNumArgsIgnored << " extra argument" <<
//	                (nNumArgsIgnored == 1 ? "" : "s") <<
//	                " ignored.  FYI." << endl;
//	    }
//
//	    // Start Winsock up
//	    WSAData wsaData;
//		int nCode;
//	    if ((nCode = WSAStartup(MAKEWORD(1, 1), &wsaData)) != 0) {
//			cerr << "WSAStartup() returned error code " << nCode << "." <<
//					endl;
//	        return 255;
//	    }
//
//	    // Call the main example routine.
//	    int retval = DoWinsock(pcHost, nPort);
//
//	    // Shut Winsock back down and take off.
//	    WSACleanup();
//	    return retval;
//}
//#include <signal.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <unistd.h>
//
//#define _XOPEN_SOURCE
//
//void my_handler(int s){
//           printf("Caught signal %d\n",s);
//           exit(1);
//
//}
//
//using namespace std;
//
//int main(int argc,char** argv)
//{
//
//   struct sigaction sigIntHandler;
//
//   sigIntHandler.sa_handler = my_handler;
//   sigemptyset(&sigIntHandler.sa_mask);
//   sigIntHandler.sa_flags = 0;
//
//   sigaction(SIGINT, &sigIntHandler, NULL);
//
//   pause();
//
//   return 0;
//}
//#include <type_traits>
//#include <iostream>
//
//template <class T>
//typename std::enable_if<std::is_integral<T>::value>::type foo(T v) {
//   std::cout << "typename std::enable_if<std::is_integral<T>>::type foo(T v)" << std::endl;
//}
//
//template <class T>
//typename std::enable_if<!std::is_integral<T>::value>::type foo(T v) {
//   std::cout << "typename std::enable_if<!std::is_integral<T>>::type foo(T v)" << std::endl;
//}
//
//int main() {
//   int i = 1;
//   float f = 1.0f;
//   foo(i); // will run first overload of the foo (for integral types)
//   foo(f); // will run second overload of the foo (for any other types)
//}

//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <stdlib.h>
//using namespace std;
//
//
//int main(){
//    int n;
//    cin >> n;
//    vector< vector<int> > a(n,vector<int>(n));
//    for(int a_i = 0;a_i < n;a_i++){
//       for(int a_j = 0;a_j < n;a_j++){
//          cin >> a[a_i][a_j];
//       }
//    }
//
//    int sum_diagonal_lr = 0;
//    for (int i = 0; i<n;i++) {
//        sum_diagonal_lr += a[i][i];
//    }
//    cout << sum_diagonal_lr;
//    int sum_diagonal_rl = 0;
//    for (int i = 0; i<n;i++) {
//        sum_diagonal_rl += a[n-i][i];
//    }
//    cout << abs(sum_diagonal_lr - sum_diagonal_rl);
//    return 0;
//}
//
//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int idProfessor = 0, idStudent = 0;
//class Person {
//    protected:
//        char name[256];
//        int age;
//    public:
//    Person() {};
//    virtual void getdata() {cout << "Person" << endl; };
//    virtual void putdata() {};
//};
//
//class Professor: public Person {
//    private:
//        int cur_id;
//        int pub;
//    public:
//    Professor() {cur_id++;
//                //cout << "Professor id " << cur_id;
//                }
//    void getdata() {
//        cout << "Professor" ;
//        cin.getline(name,256);
//        cin >> age ;
//        cin >> pub;
//    }
//    void putdata() {
//        cout << name << " " << age << " " << pub << " "  << idProfessor << endl;
//    }
//};
//
//class Student: public Person {
//    private:
//        int cur_id;
//        vector<int> marks;
//    public:
//    Student() {cur_id++;
//              cout << "Student id " << cur_id;}
//    void getdata() {
//        cout << "Student" ;
//        cin.getline(name,256);
//        cin >> age;
//        for (int i = 0; i < 6; i++)
//            cin >> marks[i];
//    }
//    void putdata(){
//        int sum;
//        for (int i = 0; i < 6; i++)
//            sum += marks[i];
//        cout << name << " " << age << " " << sum << " " << idStudent << endl;
//    }
//};
//
//int main(){
//
//    int n, val;
//    cin>>n; //The number of objects that is going to be created.
//    Person *per[n];
//
//    for(int i = 0;i < n;i++){
//
//        cin>>val;
//        if(val == 1){
//            // If val is 1 current object is of type Professor
//            per[i] = new Professor;
//
//        }
//        else per[i] = new Student; // Else the current object is of type Student
//
//        per[i]->getdata(); // Get the data from the user.
//
//    }
//
//    for(int i=0;i<n;i++)
//        per[i]->putdata(); // Print the required output for each object.
//
//    return 0;
//
//}

//Preprocessor
//#include <iostream>
//#include <vector>
//
//#define INF 0
//#define io(a) cin >> a
//#define toStr(str) #str
//#define FUNCTION(name,operator) inline void name(int &curr, int candidate) {if (curr operator candidate) curr = candidate;}
//#define foreach(v,i) for(unsigned int i = 0; i < v.size(); i++)
//
//using namespace std;
//#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
//#error Missing preprocessor definitions
//#endif
//
//FUNCTION(minimum, <)
//FUNCTION(maximum, >)
//
//int main() {
//	int n; cin >> n;
//
//		vector<int> v(n);
//		foreach(v, i) {
//			io(v)[i];
//		}
//		int mn = INF;
//		int mx = -INF;
//		foreach(v, i) {
//			minimum(mn, v[i]);
//			maximum(mx, v[i]);
//		}
//		int ans = mx - mn;
//		cout << mx << " " << mn << endl;
//		cout << toStr(Result =) <<' '<< ans;
//	return 0;
//}
//Template Specialization
//#include <iostream>
//using namespace std;
//enum class Fruit { apple, orange, pear };
//enum class Color { red, green, orange };
//
//template <typename T> struct Traits;
//
//template<>
//class Traits<Fruit> {
//public:
//	static string name(int index) {
//		Fruit t = (Fruit)index;
//		switch (t) {
//		case Fruit::apple:
//			return "apple";
//		case Fruit::orange:
//			return "orange";
//		case Fruit::pear:
//			return "pear";
//		default:
//			return "unknown";
//		}
//	}
//};
//
//template<>
//class Traits<Color> {
//public:
//	static string name(int index) {
//		Color t = (Color)index;
//		switch (t) {
//		case Color::red:
//			return "red";
//		case Color::orange:
//			return "orange";
//		case Color::green:
//			return "green";
//		default:
//			return "unknown";
//		}
//	}
//};
//int main()
//{
//	int t = 0; std::cin >> t;
//
//    for (int i=0; i!=t; ++i) {
//        int index1; std::cin >> index1;
//        int index2; std::cin >> index2;
//        cout << Traits<Color>::name(index1) << "\n";
//        cout << Traits<Fruit>::name(index2) << "\n";
//    }
//}
//Linked List
//#include <iostream>
//#include <cstddef>
//using namespace std;
//class Node
//{
//    public:
//        int data;
//        Node *next;
//        Node(int d){
//            data=d;
//            next=NULL;
//        }
//};
//class Solution{
//    public:
//	Node* insert(Node* head, int data) {
//		if (head == NULL)
//		Node* curr = new Node(data);
//		head->next = curr;
//		return curr;
//	}
//
//
//	 void display(Node *head)
//	      {
//	          Node *start=head;
//	          while(start)
//	          {
//	              cout<<start->data<<" ";
//	              start=start->next;
//	          }
//	      }
//	};
//
//
//int main()
//{
//		Node* head=NULL;
//	  	Solution mylist;
//	    int T,data;
//	    cin>>T;
//	    while(T-->0){
//	        cin>>data;
//	        head=mylist.insert(head,data);
//	    }
//		mylist.display(head);
//
//}
//#include <iostream>
//#include <set>
//#include <string>
//#include <vector>
//using namespace std;
//
//std::set<string> LCSubstr(string firstStr,string secondStr) {
//	int n = firstStr.length();
//	int m = secondStr.length();
//	cout << n << " " << m << endl;
//	std::set<string> ret;
//	vector<int> vec(n*m,0);
//
//	int z = 0;
//	for(int i = 0; i < n; ++i) {
//		for(int j = 0; j < m; ++j) {
//			if (firstStr[i] == secondStr[j]) {
//				if (i==0 || j==0)
//					vec[i*n+ j] = 1;
//				else
//					vec[i*n+j] = vec[(i-1)*n+(j-1)] + 1;
//				if (vec[i*n+j] > z) {
//					z = vec[i*n+j];
//					string s = firstStr.substr(i-z+1,i);
//					std::set<string> temp;
//					temp.insert(s);
//					ret = temp;
//				}
//				else {
//					if (vec[i*n+j] == z) {
//						string s = firstStr.substr(i-z+1,i);
//						ret.insert(s);
//					}
//				}
//			} else {
//				vec[i*n+j] = 0;
//			}
//		}
//	}
//	for (std::set<string>::iterator it=ret.begin(); it!=ret.end(); ++it)
//	    std::cout << *it << " ";
//	return ret;
//}
//
//int main() {
//	// your code goes here
//	LCSubstr("QivcjGDoqoZKuiDcFHqRBdtuPRrisYZoSyQuERxvPiYZNfbWTZHqwLiCeebfYSAgSZiOc","OAAeqEXEmijuQqDEDYBlklSWURxcLxHlFBYuWSWMYHWJVHXigdjohAundoufZ");
//	return 0;
//}

//Server
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <sys/un.h>
//#include <unistd.h>
//#include <stdio.h>
//
//#include <netinet/in.h>
//#include <netdb.h>
//#include <string.h>
//#include <dirent.h>
//
//#define PORT 0x1234
//#define HOST		"localhost"
//#define DIRSIZE 8192
//
//int main(int argc, char **argv) {
//	int server_sockfd;
//	int client_sockfd;
//	int server_len, client_len;
//	sockaddr_un server_addr;
//	sockaddr_un client_addr;
//
//	unlink("server_socket");
//	server_addr = socket(AF_UNIX, SOCK_STREAM, 0);
//
//	server_addr.sun_family = AF_UNIX;
//	    strcpy(server_addr.sun_path, "server_socket");
//	    server_len = sizeof(server_addr);
//	    bind(server_sockfd, (sockaddr*)&server_addr, server_len);
//
//	    listen(server_sockfd, 5);
//	    while(true)
//	    {
//	        char ch;
//
//	        // printf("server waiting\n");
//
//	        client_sockfd = accept(server_sockfd,
//	                        (sockaddr*)&client_addr,
//	                        &client_len);
//
//	        read(client_sockfd, &ch, 1);
//	        ++ch;
//	        write(client_sockfd, &ch, 1);
//	        close(client_sockfd);
//	    }

//	char	dir[DIRSIZE];
//	    int		sd, sd_current, cc, fromlen, tolen;
//	    int 	addrlen;
//	    struct	sockaddr_in sin;
//	    struct	sockaddr_in pin;
//
//	    /* get an internet domain socket */
//	    if((sd = socket(AF_INET, SOCK_STREAM, 0)) == 1) {
//	        perror("socket");
//	        return 1;
//	    }
//
//	    /* complete the socket structure */
//	    memset(&sin, 0, sizeof(sin));
//	    sin.sin_family = AF_INET;
//	    sin.sin_addr.s_addr = INADDR_ANY;
//	    sin.sin_port = htons(PORT);
//
//	    /* bind the socket to the port number */
//	    if(bind(sd, (struct sockaddr *) &sin, sizeof(sin)) == 1) {
//	        perror("bind");
//	        return 1;
//	    }
//
//	    /* show that we are willing to listen */
//	    if(listen(sd, 5) == -1) {
//	        perror("listen");
//	        return 1;
//	    }
//
//	    /* wait for a client to talk to us */
//	    addrlen = sizeof(pin);
//	    if((sd_current = accept(sd, (struct sockaddr *) &pin, &addrlen)) == -1) {
//	        perror("accept");
//	        return 1;
//	    }
//
//	    if(recv(sd_current, dir, sizeof(dir), 0) == -1) {
//	        perror("send");
//	        return 1;
//	    }
//
//	    /* close up both sockets */
//	    close(sd_current);
//	    close(sd);
//
//	    sleep(1);

//#include <sys/types.h>
//       #include <sys/socket.h>
//       #include <netdb.h>
//       #include <stdio.h>
//       #include <stdlib.h>
//       #include <unistd.h>
//       #include <string.h>
//
//       #define BUF_SIZE 500
//
//       int
//       main(int argc, char *argv[])
//       {
//           struct addrinfo hints;
//           struct addrinfo *result, *rp;
//           int sfd, s, j;
//           size_t len;
//           ssize_t nread;
//           char buf[BUF_SIZE];
//
//           if (argc < 3) {
//               fprintf(stderr, "Usage: %s host port msg...\n", argv[0]);
//               exit(EXIT_FAILURE);
//           }
//
//           /* Obtain address(es) matching host/port */
//
//           memset(&hints, 0, sizeof(struct addrinfo));
//           hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
//           hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
//           hints.ai_flags = 0;
//           hints.ai_protocol = 0;          /* Any protocol */
//
//           s = getaddrinfo(argv[1], argv[2], &hints, &result);
//           if (s != 0) {
//               fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
//               exit(EXIT_FAILURE);
//           }
//
//           /* getaddrinfo() returns a list of address structures.
//              Try each address until we successfully connect(2).
//              If socket(2) (or connect(2)) fails, we (close the socket
//              and) try the next address. */
//
//           for (rp = result; rp != NULL; rp = rp->ai_next) {
//               sfd = socket(rp->ai_family, rp->ai_socktype,
//                            rp->ai_protocol);
//               if (sfd == -1)
//                   continue;
//
//               if (connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1)
//                   break;                  /* Success */
//
//               close(sfd);
//           }
//
//           if (rp == NULL) {               /* No address succeeded */
//               fprintf(stderr, "Could not connect\n");
//               exit(EXIT_FAILURE);
//           }
//
//           freeaddrinfo(result);           /* No longer needed */
//
//           /* Send remaining command-line arguments as separate
//              datagrams, and read responses from server */
//
//           for (j = 3; j < argc; j++) {
//               len = strlen(argv[j]) + 1;
//                       /* +1 for terminating null byte */
//
//               if (len + 1 > BUF_SIZE) {
//                   fprintf(stderr,
//                           "Ignoring long message in argument %d\n", j);
//                   continue;
//               }
//
//               if (write(sfd, argv[j], len) != len) {
//                   fprintf(stderr, "partial/failed write\n");
//                   exit(EXIT_FAILURE);
//               }
//
//               nread = read(sfd, buf, BUF_SIZE);
//               if (nread == -1) {
//                   perror("read");
//                   exit(EXIT_FAILURE);
//               }
//
//               printf("Received %zd bytes: %s\n", nread, buf);
//           }
//
//           exit(EXIT_SUCCESS);
//       }



//       #include <sys/types.h>
//       #include <stdio.h>
//       #include <stdlib.h>
//       #include <unistd.h>
//       #include <string.h>
//       #include <sys/socket.h>
//       #include <netdb.h>
//
//       #define BUF_SIZE 500
//
//       int
//       main(int argc, char *argv[])
//       {
//           struct addrinfo hints;
//           struct addrinfo *result, *rp;
//           int sfd, s;
//           struct sockaddr_storage peer_addr;
//           socklen_t peer_addr_len;
//           ssize_t nread;
//           char buf[BUF_SIZE];
//
//           if (argc != 2) {
//               fprintf(stderr, "Usage: %s port\n", argv[0]);
//               exit(EXIT_FAILURE);
//           }
//
//           memset(&hints, 0, sizeof(struct addrinfo));
//           hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
//           hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
//           hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
//           hints.ai_protocol = 0;          /* Any protocol */
//           hints.ai_canonname = NULL;
//           hints.ai_addr = NULL;
//           hints.ai_next = NULL;
//
//           s = getaddrinfo(NULL, argv[1], &hints, &result);
//           if (s != 0) {
//               fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
//               exit(EXIT_FAILURE);
//           }
//
//           /* getaddrinfo() returns a list of address structures.
//              Try each address until we successfully bind(2).
//              If socket(2) (or bind(2)) fails, we (close the socket
//              and) try the next address. */
//
//           for (rp = result; rp != NULL; rp = rp->ai_next) {
//               sfd = socket(rp->ai_family, rp->ai_socktype,
//                       rp->ai_protocol);
//               if (sfd == -1)
//                   continue;
//
//               if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
//                   break;                  /* Success */
//
//               close(sfd);
//           }
//
//           if (rp == NULL) {               /* No address succeeded */
//               fprintf(stderr, "Could not bind\n");
//               exit(EXIT_FAILURE);
//           }
//
//           freeaddrinfo(result);           /* No longer needed */
//
//           /* Read datagrams and echo them back to sender */
//
//           for (;;) {
//               peer_addr_len = sizeof(struct sockaddr_storage);
//               nread = recvfrom(sfd, buf, BUF_SIZE, 0,
//                       (struct sockaddr *) &peer_addr, &peer_addr_len);
//               if (nread == -1)
//                   continue;               /* Ignore failed request */
//
//               char host[NI_MAXHOST], service[NI_MAXSERV];
//
//               s = getnameinfo((struct sockaddr *) &peer_addr,
//                               peer_addr_len, host, NI_MAXHOST,
//                               service, NI_MAXSERV, NI_NUMERICSERV);
//              if (s == 0)
//                   printf("Received %zd bytes from %s:%s\n",
//                           nread, host, service);
//               else
//                   fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s));
//
//               if (sendto(sfd, buf, nread, 0,
//                           (struct sockaddr *) &peer_addr,
//                           peer_addr_len) != nread)
//                   fprintf(stderr, "Error sending response\n");
//           }
//       }

//thread
//#include <iostream>
//#include <cstdlib>
//#include <pthread.h>
//
//using namespace std;
//
//#define NUM_THREADS     5
//
//void *PrintHello(void *threadid)
//{
//   long tid;
//   tid = (long)threadid;
//   cout << "Hello World! Thread ID, " << tid << endl;
//   pthread_exit(NULL);
//}
//
//int main ()
//{
//   pthread_t threads[NUM_THREADS];
//   int rc;
//   int i;
//   for( i=0; i < NUM_THREADS; i++ ){
//      cout << "main() : creating thread, " << i << endl;
//      rc = pthread_create(&threads[i], NULL,
//                          PrintHello, (void *)i);
//      if (rc){
//         cout << "Error:unable to create thread," << rc << endl;
//         exit(-1);
//      }
//   }
//   pthread_exit(NULL);
//}

//#include <iostream>
//#include <chrono> // clock functions
//#include <vector>
//#define TEST_C11_COPY 0 // 1 de test push_back copy
//#define TEST_C11_MOVE 1 // 1 de test push_back move
//using namespace std;
//int main()
//
//{
//	auto startTime = chrono::high_resolution_clock::now();
//	vector<vector<int>> V;
//
//	for(int k = 0; k < 200000; ++k) {
//		vector<int> vi(1000,k);
////		if(TEST_C11_COPY)
////			V.push_back(vi);
//
//		if(TEST_C11_MOVE)
//			V.emplace_back(std::move(vi));
//	}
//	auto endTime = chrono::high_resolution_clock::now();
//	auto total = chrono::duration_cast<chrono::milliseconds>(endTime-startTime);
//	cout << "Time is:" << total.count() << endl;
//	return 0;
//}

//#include <iostream>
//#include <ctime> // clock functions
//#include <vector>
//using namespace std;
//int main()
//{
//	clock_t startTime = clock();
//	vector<vector<int> > V;
//	for(int k = 0; k < 200000; ++k) {
//		vector<int> vi(1000,k);
//		V.push_back(vi);
//	}
//	clock_t endTime = clock();
//	cout << "Time is:" << (float)(endTime-startTime)/CLK_TCK << endl;
//	return 0;
//}


//#include <iostream>
//#include <chrono> // clock functions
//#include <vector>
//#include <cmath>
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//int main()
//
//{
//	auto startTime = chrono::high_resolution_clock::now();
//	int n;cin >> n;
//	    vector<int> vec(n);
//	    for (int i = 0; i < n; ++i) {
//	        cin >> vec[i];
//	    }
//	    std::sort (vec.begin(), vec.end());
//	    int q; cin >> q;
//
//
//	    for (int i = 0; i < q; ++i) {
//	        int k; cin >> k;
//	        std::vector<int>::iterator it;
//	        it = find(vec.begin(), vec.end(),k);
//	        if (it != vec.end()) {
//	            cout << "Yes " << it - vec.begin() + 1<< endl;
//	        } else {
//	            auto t = lower_bound(vec.begin(),vec.end(),k);
//	            cout << "No "<< t - vec.begin() + 1 << endl;
//	        }
//	    }
//
//	auto endTime = chrono::high_resolution_clock::now();
//	auto total = chrono::duration_cast<chrono::milliseconds>(endTime-startTime);
//	cout << "Time is:" << total.count() << endl;
//	return 0;
//}


//#include <iostream>
//#include <map>
//#include <string>
//#include <chrono>
//#include <thread>
//#include <mutex>
//
//std::map<std::string, std::string> g_pages;
//std::mutex g_pages_mutex;
//
//void save_page(const std::string &url, int sec)
//{
//    // simulate a long page fetch
//    std::this_thread::sleep_for(std::chrono::seconds(sec));
//    std::string result = "fake content";
//
//    //std::lock_guard<std::mutex> guard(g_pages_mutex);
//    g_pages[url] = result;
//}
//
//int main()
//{
//    std::thread t1(save_page, "http://foo", 2);
//    std::thread t2(save_page, "http://bar", 5);
//    t1.join();
//    t2.join();
//
//    // safe to access g_pages without lock now, as the threads are joined
//    for (const auto &pair : g_pages) {
//        std::cout << pair.first << " => " << pair.second << '\n';
//    }
//}

#include "transpositioncipher.h"
int main(int argc, char **argv) {
	auto startTime = std::chrono::high_resolution_clock::now();
	if (argc != 3) {
		std::cout << "usage: need two arguments" << std::endl;
	} else {
		std::string data = argv[2];
		std::transform(data.begin(), data.end(), data.begin(), ::tolower);
		transpositioncipher tc(argv[1]);
		std::cout << tc.encrypt(data) << std::endl;
		std::cout << tc.decrypt(data) << std::endl;
	}
	auto endTime = std::chrono::high_resolution_clock::now();
	auto total = std::chrono::duration_cast<chrono::milliseconds>(endTime-startTime);
	std::cout << "Time is:" << total.count() << std::endl;
	return 0;
}

