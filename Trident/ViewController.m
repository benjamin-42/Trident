//
//  ViewController.m
//  Trident
//
//  Created by Benjamin Randazzo on 06/11/2016.
//  Copyright © 2016 Benjamin Randazzo. All rights reserved.
//

#import "ViewController.h"

void initialize(void);
uint32_t leak_kernel_base(void);
void exploit(uint32_t);

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIButton *button;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)start:(id)sender {
    initialize();
    uint32_t kernel_base = leak_kernel_base();
    printf("kernel base: %p\n", (void *)kernel_base);
    exploit(kernel_base);
    
    // Update button.
    self.button.enabled = NO;
    [self.button setTitle:@"w00t root" forState:UIControlStateNormal];
}

@end
