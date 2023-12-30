package LeetCode;


import java.util.*;

public class AccountsMerge {

    public static void main(String[] args) {
//        System.out.println(accountsMerge(List.of(
//                List.of("John", "johnsmith@mail.com", "john_newyork@mail.com"),
//                List.of("John", "johnsmith@mail.com", "john00@mail.com"),
//                List.of("Mary", "mary@mail.com"),
//                List.of("John", "johnnybravo@mail.com")
//        )));
        System.out.println(accountsMerge(List.of(
                List.of("Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"),
                List.of("Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"),
                List.of("Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"),
                List.of("Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"),
                List.of("Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co")
        )));
    }

    static int[] parent;
    static int[] size;
    static List<String>[] emails;

    public static List<List<String>> accountsMerge(List<List<String>> accounts) {
        emails = new ArrayList[accounts.size()];
        Map<String, Integer> emailToIndex = new HashMap<>();
        parent = new int[accounts.size()];
        size = new int[accounts.size()];

        for (int i = 0; i < accounts.size(); i++) {
            parent[i] = i;
            size[i] = 1;
        }

        for (int i = 0; i < accounts.size(); i++) {
            List<String> account = accounts.get(i);
            emails[i] = new ArrayList<>();
            emails[i].add(account.get(0));
            int index = -1;
            for (int j = 1; j < account.size(); j++) {
                if (emailToIndex.get(account.get(j)) == null) {
                    emailToIndex.put(account.get(j), i);
                    emails[i].add(account.get(j));
                } else {
                    index = emailToIndex.get(account.get(j));
                }
            }
            if (index != -1) {
                merge(index, i);
            }
        }

        List<List<String>> result = new ArrayList<>();
        for (int i = 0; i < accounts.size(); i++) {
            if (emails[i].size() > 0) {
                List<String> strings = emails[i].subList(1, emails[i].size());
                Collections.sort(strings);
                strings.add(0, emails[i].get(0));
                result.add(strings);
            }
        }

        return result;
    }

    private static void merge(int x, int y) {
        if(x == y) return;
        List<String> newEmails = emails[y].subList(1, emails[y].size());
        emails[x].addAll(newEmails);
        emails[y].clear();
    }
}
