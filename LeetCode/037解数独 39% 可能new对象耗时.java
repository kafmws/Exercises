class Solution {
    private char[][] board;
    private Set[] rows = new HashSet[9];//每行的可选数字
    private Set[] lines = new HashSet[9];//每列上的可选数字
    private Set[] bulks = new HashSet[9];//每个九宫格的可选数字
    private Set[][] cells = new HashSet[9][9];//每个位置上可选的数字
    private int cellCnt;
    private boolean flag = false;

    private HashSet<Character> getHashSet(){
        HashSet<Character> set = new HashSet<>();
        for(char i = '1';i<='9';i++){
            set.add(i);
        }
        return set;
    }

    private void reEnsure(int i, int j){//重新计算i行与j列的cells，和该bulk中的cells
        if(cells[i][j].size()==1){//可确定
            reEnsure(i,j, (char)cells[i][j].toArray()[0]);
        }
    }

    private void reEnsure(int i, int j, char c){
        board[i][j] = c;
        cells[i][j] = null;
        cellCnt--;
        rows[i].remove(board[i][j]);
        lines[j].remove(board[i][j]);
        bulks[i/3*3+j/3].remove(board[i][j]);
        for(int k = 0;k<9;k++){
            if(cells[i][k]!=null){
                if(cells[i][k].remove(board[i][j])) reEnsure(i,k);
            }
        }
        for(int k = 0;k<9;k++){
            if(cells[k][j]!=null){
                if(cells[k][j].remove(board[i][j])) reEnsure(k,j);
            }
        }
        int baseI = i/3*3, baseJ = j/3*3;
        for(int p = baseI;p<baseI+3;p++){
            for(int q = baseJ;q<baseJ+3;q++){
                if(cells[p][q]!=null){
                    if(cells[p][q].remove(board[i][j])) reEnsure(p,q);
                }
            }
        }
    }

    private void analyzeMap(){//填充cells与普通筛法
        for(int i = 0;i<9;i++){
            rows[i] = getHashSet();
            lines[i] = getHashSet();
            bulks[i] = getHashSet();
        }
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j]!='.') {
                    rows[i].remove(board[i][j]);
                    lines[j].remove(board[i][j]);
                    bulks[i/3*3+j/3].remove(board[i][j]);
                }
            }
        }
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j]=='.'){
                    cells[i][j] = new LinkedHashSet();
                    for(Object c : rows[i]){
                        if(lines[j].contains(c)&&bulks[i/3*3+j/3].contains(c)){
                            cells[i][j].add(c);
                        }
                    }
                    cellCnt++;
                    reEnsure(i,j);
                }
            }
        }
    }

    private void unique(){//唯一筛法
        int objI,objJ,cnt;
        objI = objJ = -1;
        for(int k = 0;k<9;k++){
            List list = new LinkedList(Arrays.asList(rows[k].toArray()));
            for(int i = 0;i<list.size();i++){
                cnt = 0;
                for(int j = 0;j<9;j++){
                    if(cells[k][j]!=null&&cells[k][j].contains(list.get(i))){
                        objI = k;objJ = j;cnt++;
                        if(cnt>1)break;
                    }
                }
                if(cnt==1){//唯一
                    reEnsure(objI,objJ,(char)list.get(i));
                    if(cellCnt==0)return;
                    list.remove(i);
                    i=-1;
                }
            }
            list = null;
            list = new LinkedList(Arrays.asList(lines[k].toArray()));
            for(int j = 0;j<list.size();j++){
                cnt = 0;
                for(int i = 0;i<9;i++){
                    if(cells[i][k]!=null&&cells[i][k].contains(list.get(j))){
                        objI = i;objJ = k;cnt++;
                        if(cnt>1)break;
                    }
                }
                if(cnt==1){//唯一
                    reEnsure(objI,objJ,(char)list.get(j));
                    if(cellCnt==0)return;
                    list.remove(j);
                    j = -1;
                }
            }
            list = null;
            list = new LinkedList(Arrays.asList(bulks[k].toArray()));
            int baseI = k/3*3, baseJ = k%3*3;
            for(int c = 0;c<list.size();c++){
                cnt = 0;
                for(int i = baseI;i<baseI+3;i++){
                    for(int j = baseJ;j<baseJ+3;j++){
                        if(cells[i][j]!=null&&cells[i][j].contains(list.get(c))){
                            objI = i;objJ = j;cnt++;
                            if(cnt>1)break;
                        }
                    }
                }
                if(cnt==1){//唯一
                    reEnsure(objI,objJ,(char)list.get(c));
                    if(cellCnt==0)return;
                    list.remove(c);
                    c=-1;
                }
            }
        }
    }

    private boolean examFeasibility(int i, int j){
        for(int k = 0; k<9;k++){
            if(board[i][k]==board[i][j]&&k!=j)return false;
            if(board[k][j]==board[i][j]&&k!=i)return false;
        }
        int baseI = i/3*3, baseJ = j/3*3;
        for(int p = baseI;p<baseI+3;p++){
            for(int q = baseJ;q<baseJ+3;q++){
                if(board[p][q]==board[i][j]&&p!=i&&q!=j)return false;
            }
        }
        return true;
    }

    private void re(int cellIndex, int i, int j){//回溯 子集法
        if(cellIndex>=cellCnt){flag=true;return;}
        j++;if(j==9){i++;j=0;}
        out:
        for(;i<9;j=0,i++){
            for(;j<9;j++){
                if(cells[i][j]!=null)break out;
            }
        }
        Object[] chars = cells[i][j].toArray();
        for(int k = 0;k<chars.length;k++){
            board[i][j] = (char) chars[k];
            if(examFeasibility(i,j)){
                re(cellIndex+1,i,j);
                if(flag)return;
            }
        }
        board[i][j] = '.';
    }

    public void solveSudoku(char[][] board) {
        this.board = board;
        analyzeMap();
        if(cellCnt==0)return;
        int exam;
        do{
            exam = cellCnt;
            unique();
        }
        while(exam!=cellCnt);
        re(0,0,-1);
    }
}

//41%
class Solution {
    private char[][] board;
    private Set[] rows = new HashSet[9];//每行的可选数字
    private Set[] lines = new HashSet[9];//每列上的可选数字
    private Set[] bulks = new HashSet[9];//每个九宫格的可选数字
    private Set[][] cells = new HashSet[9][9];//每个位置上可选的数字
    private int cellCnt;
    private boolean flag = false;

    private HashSet<Character> getHashSet(){
        HashSet<Character> set = new HashSet<>();
        for(char i = '1';i<='9';i++){
            set.add(i);
        }
        return set;
    }

    private void reEnsure(int i, int j){//重新计算i行与j列的cells，和该bulk中的cells
        if(cells[i][j].size()==1){//可确定
            reEnsure(i,j, (char)cells[i][j].toArray()[0]);
        }
    }

    private void reEnsure(int i, int j, char c){
        board[i][j] = c;
        cells[i][j] = null;
        cellCnt--;
        rows[i].remove(board[i][j]);
        lines[j].remove(board[i][j]);
        bulks[i/3*3+j/3].remove(board[i][j]);
        for(int k = 0;k<9;k++){
            if(cells[i][k]!=null){
                if(cells[i][k].remove(board[i][j])) reEnsure(i,k);
            }
        }
        for(int k = 0;k<9;k++){
            if(cells[k][j]!=null){
                if(cells[k][j].remove(board[i][j])) reEnsure(k,j);
            }
        }
        int baseI = i/3*3, baseJ = j/3*3;
        for(int p = baseI;p<baseI+3;p++){
            for(int q = baseJ;q<baseJ+3;q++){
                if(cells[p][q]!=null){
                    if(cells[p][q].remove(board[i][j])) reEnsure(p,q);
                }
            }
        }
    }

    private void analyzeMap(){//填充cells与普通筛法
        for(int i = 0;i<9;i++){
            rows[i] = getHashSet();
            lines[i] = getHashSet();
            bulks[i] = getHashSet();
        }
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j]!='.') {
                    rows[i].remove(board[i][j]);
                    lines[j].remove(board[i][j]);
                    bulks[i/3*3+j/3].remove(board[i][j]);
                }
            }
        }
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j]=='.'){
                    cells[i][j] = new LinkedHashSet();
                    for(Object c : rows[i]){
                        if(lines[j].contains(c)&&bulks[i/3*3+j/3].contains(c)){
                            cells[i][j].add(c);
                        }
                    }
                    cellCnt++;
                    reEnsure(i,j);
                }
            }
        }
    }

    private boolean examFeasibility(int i, int j){
        for(int k = 0; k<9;k++){
            if(board[i][k]==board[i][j]&&k!=j)return false;
            if(board[k][j]==board[i][j]&&k!=i)return false;
        }
        int baseI = i/3*3, baseJ = j/3*3;
        for(int p = baseI;p<baseI+3;p++){
            for(int q = baseJ;q<baseJ+3;q++){
                if(board[p][q]==board[i][j]&&p!=i&&q!=j)return false;
            }
        }
        return true;
    }

    private void re(int cellIndex, int i, int j){//回溯 子集法
        if(cellIndex>=cellCnt){flag=true;return;}
        j++;if(j==9){i++;j=0;}
        out:
        for(;i<9;j=0,i++){
            for(;j<9;j++){
                if(cells[i][j]!=null)break out;
            }
        }
        Object[] chars = cells[i][j].toArray();
        for(int k = 0;k<chars.length;k++){
            board[i][j] = (char) chars[k];
            if(examFeasibility(i,j)){
                re(cellIndex+1,i,j);
                if(flag)return;
            }
        }
        board[i][j] = '.';
    }

    public void solveSudoku(char[][] board) {
        this.board = board;
        analyzeMap();
        if(cellCnt==0)return;
        System.out.println(Arrays.deepToString(board));
        re(0,0,-1);
    }
}