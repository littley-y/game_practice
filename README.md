### 모든 프로그램은 macOS를 기반으로 하여 만들어졌기 때문에, 다른 운영체제에서는 실행할 수 없습니다.  
## **기본 사용 설명서**
플레이 가능한 프로그램은 `cub3D`, `so_long`, `astar` 입니다. 둘 모두 `C99` 표준을 준수하며 만들었습니다.
각 프로그램 폴더에서 make 혹은 `make all`을 입력 한 후, `./프로그램이름 maps/맵이름` 을 입력하여 실행시키면 됩니다. 실행 파일을 제외하고 오브젝트 파일을 지우려면 `make clean`을, 실행파일 까지 지우려면 `make fclean`을, 삭제 후 재컴파일 하려면 `make re`를 입력하시면 됩니다.
|제목|설명|
|:---:|:---:|
|사용 라이브러리|MLX|
|개발 OS|Mac OS|
|사용 IDE|Visual Studio Code|

## **MLX(MinilibX)**
`mlx`는 42 그룹에서 만든 라이브러리로, 그래픽 과제를 위해 제공되었습니다. 이 라이브러리는 macOS에서 빠른 그래픽 렌더링을 위한 X11 라이브러리를 이용해서 만들어졌으며, 응용 프로그램의 그래픽 화면 표시 및 사용자 인터페이스에 대한 기능을 제공합니다. 그래픽 어플리케이션을 구현할 때 `mlx`에 내장된 다양한 함수를 사용하면 쉽게 구현이 가능합니다. 주요 기능으로 window를 화면에 띄우기, image를 파일에서 읽어와서 window에 띄우기, 키 혹은 마우스의 입력을 가로채기, 무한 루프를 통해 함수를 계속 실행시키기 등이 있습니다.

## **LIBFT**
`libft`는 다양한 함수를 직접 구현하여 라이브러리를 만드는 것이 목표인 프로젝트입니다. 메모리 관리 함수, `string.h`에 있는 유용한 함수, `Linked list`, 기타 필요한 함수를 작성했고, `Makefile`을 통해 컴파일됩니다. `libft.h`에 구현한 함수들의 목록이 있습니다. 이 라이브러리를 이용하여 `so_long`과 `cub3D`을 만들 때 필요한 부가 함수를 효율적으로 사용할 수 있습니다. <br/>

---

## **1. so_long**

`so_long`은 `mlx` 라이브러리를 이용해 만든 간단한 탈출 프로그램입니다. `WASD`로 이동할 수 있고, 모든 우유를 먹어야 탈출할 수 있습니다. 플레이어의 키 입력이 일어날 때 마다 소가 움직입니다. 소와 마주쳐서 우유를 뺏기면 프로그램이 종료되니 주의하세요! </br>
<img src="https://user-images.githubusercontent.com/103979407/219643931-628671ac-4c5a-4019-9113-2b99ebde7499.gif" width="500">

---

## **2. cub3D**

`cub3d`는 `mlx` 라이브러리와 레이 캐스팅 기술을 활용하여 만든 3D를 흉내내는 프로그램입니다. 2D의 맵에서 플레이어의 위치를 기준으로 시야각 및 카메라 평면을 설정하고, 벽까지의 거리를 기반으로 텍스쳐를 입히는 방식으로 만들어졌습니다. `WASD`로 이동할 수 있고, `M`키로 맵을 끄고 킬 수 있습니다. 마우스를 좌우 벽쪽으로 가까이 가져갈수록 시점이 더 빠르게 회전합니다. 카드를 먹은 만큼만 문이 열리기 때문에, 올바른 출구를 찾는 것이 중요한 프로그램입니다! </br>
<img src="https://user-images.githubusercontent.com/103979407/219648554-bd5f8795-a460-49ce-b950-e0629f5c4205.gif" width="500" height="300">

---

## **3. astar**

기본적인 길찾기 알고리즘인 `A* 길찾기`를 이용하여 만든 간단한 프로그램입니다. `WASD`키로 이동할 수 있고, 마우스로 맵 테두리의 벽을 제외한 빈 공간을 클릭하면 벽이 만들어집니다. 키 입력 혹은 마우스 입력이 일어날 때 알고리즘을 통한 최적 루트가 초록색 길로 안내되고, 터미널로 해당 길을 통해 탈출할 수 있을 때 까지 몇 걸음이 필요한지 출력됩니다. </br>
<img src="https://user-images.githubusercontent.com/103979407/219642769-61ee77d6-c15e-4e2b-9f0d-4203a2206f14.gif" width="500">

---

## **4. containers**
기초적인 자료구조 및 템플릿을 통한 제네릭 프로그래밍에 대한 이해를 목표로 한 프로젝트입니다. C++98 표준을 기반으로 만들었습니다. STL의 `vector`, `stack`, `map`, `set`과 `iterator`를 직접 구현했습니다. 추가적으로 STL에 필요한

• `std::iterator_traits` </br>
• `std::reverse_iterator` </br>
• `std::enable_if`(C++98에는 없는 기능이지만, 과제를 위해 직접 구현했습니다.) </br>
• `std::is_integral` </br>
• `std::equal` </br>
• `std::lexicographical_compare` </br>
• `std::pair` </br>
• `std::make_pair` </br>

등을 모두 구현했습니다.
