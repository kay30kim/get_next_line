/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:11:24 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/01 16:00:11 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // 파일 디스크립터 관련 헤더

int	main(void)
{
    int fd; // 파일 디스크립터
	char *line;

	// 파일 디스크립터를 여는 코드
	fd = open("sample.txt", O_RDONLY); // "sample.txt"는 읽을 파일의 경로

	if (fd < 0)
	{
		// 파일 열기 실패
		return (1);
	}

	// 파일로부터 한 줄씩 읽기
	while ((line = get_next_line(fd)) != NULL)
	{
		// 읽은 줄 출력
		printf("%s\n", line);
		free(line); // 메모리 누수 방지를 위해 메모리 해제
	}

	// 파일 디스크립터와 작업이 끝났으므로 닫음
	close(fd);

	return (0);
}
