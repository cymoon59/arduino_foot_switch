발판 스위치
발판 스위치를 만들기로 맘먹은 계기는 Emacs를 배워보기로 맘먹고 배우기 시작했는데 한 3일쯤 Emacs로 일을 하다보니 슬슬 문제가 생기기 시작했다. 바로 새끼 손가락이 아파오기 시작한 것이다.
이는 Emacs를 배우려고 고민했을 때 사람들의 한결같은 반응 중 하나가 손가락이 아파서 못하겠다는 것이었다.
별거 아닐 거라고 생각하고 시작했지만 상당히 아파왔다.

구글에 검색을 해 본 결과 해결 방안들을 찾을 수 있었다.
1. Capslock을 Ctrl로 변경해서 사용하는 방법: 이는 Emacs로 변경하기 전부터 사용하던 방식이다. 원래의 Ctrl을 클릭하는 것보다는 편하지만 그걸로는 부족했다.
2. 키보드를 교체하는 방법: 해피해킹이나 키네시스 혹은 내츄럴 키보드로 교체를 하라는 것이었다. 내츄럴 키보드는 이전에 사용해 봤지만 나랑 잘 맞지 않는 문제가 있고, 해피해킹이랑 키네시스는 30만원을 넘는 고가 제품들이라서 좌절했다.
3. 발판 스위치를 사용하는 방법: 가장 생소하고 처음듣는 이야기였다. 알아보니 키네시스에서도 발판 스위치를 별도로 판매하는 것을 확인했다.

왠지 발판 스위치를 쓰면 편해질 것 같은 생각이 막 들었다.
전자 지식은 전무하지만 집에서 놀고있는 아두이노가 생각이 났다.
바로 검색...역시 이미 만든 사람들이 있다.

준비물인 발판과 스위치만 있으면 될 거 같았다.

결과물

모드 3개:
1. Emacs모드: Ctrl,Alt로 매핑
2. 디버그모드: F7, F8로 매핑
3. 웹툰 모드: Page Up/Page Down으로 매핑

모드 변경: 버튼 클릭 시 모드가 변경됨

일주일 사용 소감:
발판이 의외로 높아서 클릭이 편하지는 않다. 웹툰이나 디버그 모드 시에는 쓸만한데 막상 원래의 기능인 Emacs모드는 손처럼 빠르게 반응하기가 힘들어서 좀 더 편하게 클릭할 수 있는 방법을 찾아보고 있다.
현재 가장 많이 쓰이는 건 점심시간에 웹툰을 볼 때이다. 의자에 편하게 기대어 웹툰을 감상한다. 

만드는 방법
1. 아두이노 버튼 클릭해서 LED 불켜기
   아두이노의 필요지식은 딱 2가지이다. 아두이노로 클릭 이벤트를 받고 LED를 켤 수 있으면 된다. 
3. 버튼 연결
4. 스케치 작성
5. 아두이노를 HID Device로 변경하기
6. 버튼을 발판으로 변경
7. 모드 변경 기능 추가
8. RGB LED 추가

