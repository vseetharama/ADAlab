#include &lt;stdio.h&gt;

#define MAX 20

void warshall(int n, int r[MAX][MAX]);

int main() {
int r[MAX][MAX]; // 2-D array to store the reachability matrix
int i, j, n;

printf(&quot;Enter the number of nodes/vertices: &quot;);
scanf(&quot;%d&quot;, &amp;n);

printf(&quot;Enter the adjacency matrix (1 for edge, 0 for no edge):\n&quot;);
for(i = 1; i &lt;= n; i++) {
for(j = 1; j &lt;= n; j++) {
scanf(&quot;%d&quot;, &amp;r[i][j]);
}
}

warshall(n, r);

return 0;
}

void warshall(int n, int r[MAX][MAX]) {
int i, j, k;

// Calculation of Transitive Closure
for(k = 1; k &lt;= n; k++) {
for(i = 1; i &lt;= n; i++) {
for(j = 1; j &lt;= n; j++) {
r[i][j] = r[i][j] || (r[i][k] &amp;&amp; r[k][j]);
}
}
}

printf(&quot;Transitive closure matrix is:\n&quot;);
for(i = 1; i &lt;= n; i++) {
printf(&quot;\t%d&quot;, i);
}

printf(&quot;\n\t--------------------------------------------\n&quot;);
for(i = 1; i &lt;= n; i++) {
printf(&quot;%d|\t&quot;, i);
for(j = 1; j &lt;= n; j++) {
printf(&quot;%d\t&quot;, r[i][j]);
}
printf(&quot;\n&quot;);
}
}
