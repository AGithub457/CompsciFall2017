import java.util.*;

public class ElectionResults {
  public static Candidate[] candidates = new Candidate[] {
    new Candidate(2016, "Hillary", "Clinton", 22, 4.3),
    new Candidate(2016, "Donald", "Trump", 5, 3),
  };

  public static void main(String[] args) {
    for (Candidate i : candidates) {
      if(i.getYear() == 2012) {
        System.out.println(i.getYear() + "\t" + i.getFName() + "\t" + i.getLName() + "\t"+ i.getVoteCount() + "\t" + i.getPct());
      }
    }
  }
}
