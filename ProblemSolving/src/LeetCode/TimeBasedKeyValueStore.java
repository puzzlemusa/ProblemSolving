package LeetCode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class TimeMap {

    private Map<String, List<Value>> map;

    public TimeMap() {
        map = new HashMap<>();
    }

    public void set(String key, String value, int timestamp) {
        map.computeIfAbsent(key, k -> new ArrayList<>()).add(new Value(value, timestamp));
    }

    public String get(String key, int timestamp) {
        List<Value> values = map.get(key);

        if (values == null) {
            return "";
        }

        int left = 0;
        int right = values.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (values.get(mid).timestamp == timestamp) {
                return values.get(mid).value;
            }

            if (timestamp < values.get(mid).timestamp) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left == 0 ? "" : values.get(left - 1).value;
    }

    public record Value(String value, int timestamp) {
    }
}

public class TimeBasedKeyValueStore {

    public static void main(String[] args) {
        TimeMap timeMap = new TimeMap();
        timeMap.set("foo", "bar", 1);
        System.out.println(timeMap.get("foo", 1));
        System.out.println(timeMap.get("foo", 3));
        timeMap.set("foo", "bar2", 4);
        System.out.println(timeMap.get("foo", 4));
        System.out.println(timeMap.get("foo", 5));
        System.out.println("------------------------");

        TimeMap timeMap1 = new TimeMap();
        timeMap1.set("love", "high", 10);
        timeMap1.set("love", "low", 20);
        System.out.println(timeMap1.get("love", 5));
        System.out.println(timeMap1.get("love", 10));
        System.out.println(timeMap1.get("love", 15));
        System.out.println(timeMap1.get("love", 20));
        System.out.println(timeMap1.get("love", 25));
    }
}
