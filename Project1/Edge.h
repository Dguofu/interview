#pragma once

#include <vector>
using namespace std;
class Edge {
	int from;
	int to;
	int weight;
public:
	Edge(int w,int v,int weight) {

		from = w;
		to = v;
		this->weight = weight;
	}
	int from() { return this->from; };
	int to() { return this->to; };
	int weight() { return this->weight; };

};
class choumi
{
public:
	choumi(int n) {

		v = n;

		G = vector<vector<Edge*>>(n, vector<Edge*>(n, NULL));


	}
	void add(int begin,int end,Edge e) {
		G[begin][end] = new Edge(begin, end, e.weight());
	}
	int V() const {
		return v;
	}
	~choumi();
	class adjex {
	private:
		choumi& g;
		int value;
		int index;
	public:

		adjex() = default;

		adjex( choumi& gg, int value)
			: g(gg)
		{
			this->value = value;
		}
		Edge* begin() {
			index = 0;
			return next();
		}
		Edge* next() {
			for (index++ ; index <g.V(); index++)
			{
				if (g.G[value][index]) {

				}
			}
		}
	};
private:
	int v;
	int e;
	vector<vector<Edge*>> G;

};


choumi::~choumi()
{
}