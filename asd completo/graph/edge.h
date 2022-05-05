#ifndef _EDGE_H
#define _EDGE_H


template <typename T, typename W> class Graph;



template <typename T, typename W> class Edge {
	
	friend class Graph <T, W>;
	
	public:
		
		// costruttore con passaggio di parametri
		
		Edge (T to, W weight) {
			
			this->to = to;
			this->weight = weight;
			
		}
		
		
	private:
		
		T to;
		W weight;
		
};



#endif
