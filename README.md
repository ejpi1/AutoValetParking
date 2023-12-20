# AutoValetParking
공항에서 주로 사용하는 Auto Valet Parking을 구현하고자, Arduino Uno R3를 사용하였습니다.

## 주된 구현방식
- L298N을 사용한 4륜 모터 제어
- 포토트랜지스터를 사용한 적외선 인식

## 사용된 파일
1. `car_code/*`: 차량의 주행을 제어하는 코드입니다.
2. `parking_signal/*`: 주차장의 주차 감지 기능을 담은 코드입니다.
3. `remote_controller/*`: 디지털 키를 조작하는 코드입니다.

### Flowchart
<img width="30%" src="https://github.com/ejpi1/AutoValetParking/assets/150632681/3dd2f36a-0435-421d-889e-de3d47b6680e"/>
<img width="30%" src="https://github.com/ejpi1/AutoValetParking/assets/150632681/e0243770-d701-4e97-8b3c-bf50def90982"/>

## 기여자
- 2019041076 정찬민 (Chaoma74)
- 2019081194 임재혁 (blacksketch19)
- 2019093718 이신선 (ejpi1)