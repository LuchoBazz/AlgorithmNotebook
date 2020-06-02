// Made by Luis Miguel Baez
// lmbaeza@unal.edu.co

import java.util.List;
import java.util.ArrayList;

public class KMP {
    
    public List<Integer> search(String txt, String pat) {
        List<Integer> output = new ArrayList<>();
        
        int N = txt.length();
        int M = pat.length();
        
        if(M > N) return output;
        
        // Longest Prefix Suffix
        int lps[] = new int[M]; 
        int j = 0; // index for pat[] 
        
        // Calcular el array con los datos del 'Longest Prefix Suffix'
        LPS(pat, lps); 
  
        int i = 0; // index for txt[] 
        
        while (i < N) { 
            if (pat.charAt(j) == txt.charAt(i)) { 
                j++; 
                i++; 
            }
            
            if (j == M) {
                // Found pattern at index (i-j)
                output.add(i-j);
                j = lps[j - 1]; 
            } else if (i < N && pat.charAt(j) != txt.charAt(i)) { 
                if (j != 0) {
                    j = lps[j - 1]; 
                } else {
                    i = i + 1; 
                }
            } 
        }
        return output;
    } 
    
    private void LPS(String pat, int lps[]) { 
        int M = pat.length();
        int len = 0; 
        int i = 1; 
        lps[0] = 0; // lps[0] siempre es 0
  
        // Calcular lps[i] for i = 1 to M-1 
        while (i < M) { 
            if (pat.charAt(i) == pat.charAt(len)) { 
                len++; 
                lps[i] = len; 
                i++; 
            } else { 
                if (len != 0) { 
                    len = lps[len - 1]; 
                } else { 
                    lps[i] = len; 
                    i++; 
                } 
            } 
        }
    }
    
    public static void main(String[] args) {
        String txt = "ABABDABACDABABCABAB"; 
        String pat = "ABAB"; 
        List<Integer> ans = new KMP().search(txt, pat);
        
        for(Integer index: ans) {
            System.out.println("Found pattern at index: "+ index);
        }
    }
}