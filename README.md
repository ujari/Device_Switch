# 디바이스 활성화/비활성화 프로그램
### 소개
장치관리자에서 디바이스를 직접 활성화/비활성화 하는 번거로움을 줄여보세요!

### 사용 방법
main.c파일 속 "Your instant ID" 부분에 제어하고 싶은 디바이스의 인스턴트ID를 기입하세요.
  - 인스턴트ID 찾기
    장치관리자 - 속성 - 자세히 - 장치 인스턴트 경로
  - 주의 사항
    '\'를 c언어에 알맞게 '//'로 고쳐주세요. ex)HID\GXTP216&COL83\5&5454 -> HID\\GXTP216&COL83\\5&5454
