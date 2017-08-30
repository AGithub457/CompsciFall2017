public class Candidate {

  private int year, voteCount;
  private String fName, lName;
  private double pct;

  public Candidate(int year, String fName, String lName, int voteCount, double pct) {
    this.year = year;
    this.voteCount = voteCount;
    this.fName = fName;
    this.lName = lName;
    this.pct = pct;
  }

  public int getYear() {
    return year;
  }

  public int getVoteCount() {
    return voteCount;
  }

  public String getFName() {
    return fName;
  }

  public String getLName() {
    return lName;
  }

  public double getPct() {
    return pct;
  }

}
