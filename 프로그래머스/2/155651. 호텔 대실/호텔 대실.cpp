#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int TimeConvert(const string &strTime)
{
    int time = 0;

    int hh = std::stoi(strTime.substr(0, strTime.find(':')));
    int mm = std::stoi(strTime.substr(strTime.find(':') + 1));

    time = (hh * 60) + mm;

    return time;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> bookings;

    // 시간 변환 및 정리
    for (const auto& time : book_time) 
    {
        bookings.emplace_back(TimeConvert(time[0]), TimeConvert(time[1]) + 10);
    }

    // 체크인 시간 기준으로 정렬
    sort(bookings.begin(), bookings.end());

    // 우선순위 큐(최소 힙)를 사용하여 퇴실 시간을 관리
    priority_queue<int, vector<int>, greater<int>> room_end_times;

    for (const auto& booking : bookings) 
    {
        int check_in = booking.first;
        int check_out = booking.second;

        // 현재 예약의 체크인 시간보다 이전에 끝난 방 제거
        if (!room_end_times.empty() && room_end_times.top() <= check_in) 
        {
            room_end_times.pop();
        }

        // 현재 예약 추가
        room_end_times.push(check_out);
    }

    // 필요한 객실 수는 우선순위 큐에 남은 항목 수
    return room_end_times.size();
}