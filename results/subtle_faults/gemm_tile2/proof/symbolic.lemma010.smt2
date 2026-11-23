; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_5 () (_ BitVec 32))
(assert
 (let ((?x538307 (bvmul arg0_5 arg1_4)))
(let ((?x532546 (bvmul (_ bv4294967295 32) ?x538307)))
(let ((?x410600 (bvmul arg0_5 arg1_5)))
(let ((?x489122 (bvadd ?x410600 ?x532546)))
(and (distinct ?x489122 (_ bv0 32)) true))))))
(check-sat)
