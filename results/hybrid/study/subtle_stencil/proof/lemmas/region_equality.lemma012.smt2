; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x327693 (bvmul arg0_6 arg2_0)))
(let ((?x336146 (bvmul (_ bv4294967295 32) ?x327693)))
(let ((?x330646 (bvmul arg0_6 arg2_1)))
(let ((?x289844 (bvadd ?x330646 ?x336146)))
(and (distinct ?x289844 (_ bv0 32)) true))))))
(check-sat)
