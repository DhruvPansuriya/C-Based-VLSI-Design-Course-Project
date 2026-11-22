; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x161 (bvmul arg0_8 arg1_8)))
(let ((?x21738 (bvmul (_ bv4294967295 32) ?x161)))
(let ((?x102 (bvmul arg0_8 arg1_2)))
(let ((?x3510 (bvadd ?x102 ?x21738)))
(and (distinct ?x3510 (_ bv0 32)) true))))))
(check-sat)
