public int[] dailyTemperatures(int[] T) {
        int[] days = new int[T.length];
        for (int i = 0; i < T.length; i++) {
            for (int j = i + 1; j < T.length; j++) {
                if (T[j] > T[i]) {
                    days[i] = j - i;
                    break;
                }
            }
        }
        return days;
    }